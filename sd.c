#include "spi.h"
#include "sd.h"
#include "LPC176x.h"
#include "uart.h"

volatile unsigned char sd_block_buffer[512]; //caller defines buffer
int last_sd_error_code;
int sd_type;

int sd_get_error_code(void)
{
	return last_sd_error_code;
}

void init_sd(void)
{
	rFIO0DIR |= 1; //Set cs pin for terminal as output pin 9 on mbed which is 0.0 for LCP1768
}


void spi_select_sd(void)
{
	rFIO0CLR |= 1;  //select slave
}

void spi_release_sd(void)
{
	rFIO0SET |= 1;  //release slave
}

unsigned char sd_send_command(unsigned char cmd, unsigned long arg)
{
	unsigned char response = sd_send_command_no_release(cmd, arg);
	spi_release_sd();
	return response;
}

unsigned char sd_send_command_no_release(unsigned char cmd, unsigned long arg)
{
	int retry = 0;
	unsigned char response, s, crc;
	 spi_select_sd();
	 spi_transfer(cmd | 0x40);
	 


  // send argument
  spi_transfer(arg>>24);
spi_transfer(arg>>16);
spi_transfer(arg>>8);
spi_transfer(arg);

  // send CRC
  crc = 0XFF;
  if (cmd == CMD0) crc = 0X95;  // correct crc for CMD0 with arg 0
  if (cmd == CMD8) crc = 0X87;  // correct crc for CMD8 with arg 0X1AA

  spi_transfer(crc);

  // wait for response
  while((response = spi_transfer(0xff)) == 0xff) //wait response
   {if(retry++ > 254) break; //time out 
	   
   }
   
   //spi_release_sd();
   return response;
}

unsigned char sd_reset(void)
{ 
 unsigned char response;
 unsigned int retry = 0; 
 int i;
 
 for (i = 0; i < 10; i++) spi_transfer(0XFF);
 
/* After power up (including hot insertion, i.e. inserting a card when the bus is operating) the SD Card
enters the idle state. In case of SD host, CMD0 is not necessary. In case of SPI host, CMD0 shall be
the first command to send the card to SPI mode.*/ 
 do
{
   response = sd_send_command(CMD0, 0); //send 'reset & go idle' command
   if(++retry>254){
	   last_sd_error_code = response;
   return ERROR_RESET_GO_IDLE;}   
} while(response != R1_IDLE_STATE);


if ((sd_send_command(CMD8, 0x1AA) & R1_ILLEGAL_COMMAND)) {
    sd_type = SD_CARD_TYPE_SD1;
  } else {
    
    sd_type = SD_CARD_TYPE_SD2;
  }



retry=0;
do
{
    response = sd_send_acmd(ACMD41, 0X40000000); //activate card's initialization process
    if(++retry>20254){
		last_sd_error_code = response;
    return ERROR_INIT;}  
}while(response!= R1_READY_STATE);
//CRC disabled in SPI mode so we will keep it that way.
retry = 0;
do
{  
  response = sd_send_command(16, 512); //set block size to 512
  if(++retry>10) 
  {
  return 8;		//time out
  last_sd_error_code = response;
}  
}while (response != R1_READY_STATE);
return 0;
}//end of SD_reset function


unsigned char sd_read_block(unsigned long block)
{
     
     int i,j,retry = 0;
     unsigned char status;
     
   //block <<= 9;
    last_sd_error_code =sd_send_command_no_release(CMD17, block);
		if (last_sd_error_code != R1_READY_STATE) {
			spi_release_sd();;
      return SD_CARD_ERROR_CMD17;

    }
    
    status = spi_transfer(0xff);
    while(status != 0xfe) //wait for start block token 0xfe 
{  
	//wait
	for(j=0; j<80000;j++)
	{
		
	}
  if(retry++ > 1600)
  {
    
    last_sd_error_code = status;
    return SD_CARD_TOKEN_TIME_OUT; //return if time-out
  }//end time out for token
  
  status = spi_transfer(0xff);
}
  
for(i=0; i<512; i++) //read 512 bytes
  sd_block_buffer[i] = spi_transfer(0xff);
spi_transfer(0xff); //receive incoming CRC (16-bit), CRC is ignored here
spi_transfer(0xff);
spi_transfer(0xff); //extra 8 clock pulses
spi_release_sd();

  
  return SD_NO_ERROR;


}//end of read block

unsigned char sd_send_acmd(unsigned char cmd,unsigned long arg) {
    sd_send_command(CMD55, 0);
    return sd_send_command(cmd, arg);
  }

