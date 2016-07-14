#ifndef SD_H
#define SD_H

void init_sd(void);
void spi_release_sd(void);
void spi_select_sd(void);
unsigned char sd_send_command(unsigned char command, unsigned long argument);
unsigned char sd_send_command_no_release(unsigned char cmd, unsigned long arg);
unsigned char sd_reset(void);
unsigned char sd_read_block(unsigned long Rstartblock);
int sd_get_error_code(void);
unsigned char sd_send_acmd(unsigned char cmd,unsigned long arg) ;

#define ERROR_RESET_GO_IDLE	1
#define ERROR_INIT 2
#define SD_NO_ERROR 0
#define ERROR_SET_BLOCK_SIZE	8



// SD card commands
/** GO_IDLE_STATE - init card in spi mode if CS low */
#define CMD0 0X00
/** SEND_IF_COND - verify SD Memory Card interface operating condition.*/
#define CMD8 0X08
/** SEND_CSD - read the Card Specific Data (CSD register) */
#define CMD9 0X09
/** SEND_CID - read the card identification information (CID register) */
#define CMD10 0X0A
/** SEND_STATUS - read the card status register */
#define CMD13 0X0D
/** READ_BLOCK - read a single data block from the card */
#define CMD17 0X11
/** WRITE_BLOCK - write a single data block to the card */
#define CMD24 0X18
/** WRITE_MULTIPLE_BLOCK - write blocks of data until a STOP_TRANSMISSION */
#define CMD25 0X19
/** ERASE_WR_BLK_START - sets the address of the first block to be erased */
#define CMD32 0X20
/** ERASE_WR_BLK_END - sets the address of the last block of the continuous
    range to be erased*/
#define CMD33 0X21
/** ERASE - erase all previously selected blocks */
#define CMD38 0X26
/** APP_CMD - escape for application specific command */
#define CMD55 0X37
/** READ_OCR - read the OCR register of a card */
#define CMD58 0X3A
/** SET_WR_BLK_ERASE_COUNT - Set the number of write blocks to be
     pre-erased before writing */
#define ACMD23 0X17
/** SD_SEND_OP_COMD - Sends host capacity support information and
    activates the card's initialization process */
#define ACMD41 0X29
//------------------------------------------------------------------------------
/** status for card in the ready state */
#define R1_READY_STATE 0X00
/** status for card in the idle state */
#define R1_IDLE_STATE 0X01
/** status bit for illegal command */
#define R1_ILLEGAL_COMMAND 0X04
/** start data token for read or write single block*/
#define DATA_START_BLOCK 0XFE
/** stop token for write multiple blocks*/
#define STOP_TRAN_TOKEN 0XFD
/** start data token for write multiple blocks*/
#define WRITE_MULTIPLE_TOKEN 0XFC
/** mask for data response tokens after a write block operation */
#define DATA_RES_MASK 0X1F
/** write data accepted token */
#define DATA_RES_ACCEPTED 0X05



#define SD_CARD_TYPE_SD1 1
#define SD_CARD_TYPE_SD2	2
#define SD_CARD_ERROR_CMD17 17

#define SD_CARD_TOKEN_TIME_OUT 4
#endif
