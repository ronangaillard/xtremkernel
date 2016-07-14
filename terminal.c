#include "terminal.h"
#include "spi.h"
#include "utilities.h"
#include "LPC176x.h"
#include "font8x8.h"

int cursor_position_x = 1;
int cursor_position_y = 0;
unsigned char screen_buffer[64*64]; // contains all characters on screen

char character_postition = 0;
//set : |= ou juste = ?
void terminal_init()
{
	//Already done in InitSPI()
	//rFIO0DIR |= (1<<16); //Set cs pin for terminal as output
	//__end();
	
	int i;
	 wr(J1_RESET, 1);           // HALT coprocessor
 __wstart(RAM_SPR);            // Hide all sprites
 for (i = 0; i < 512; i++)
  {
    xhide();
}
  __end(); //release Select Pin
  fill(RAM_PIC, 0, 1024 * 10);  // Zero all character RAM
  fill(RAM_SPRPAL, 0, 2048);    // Sprite palletes black
  fill(RAM_SPRIMG, 0, 64 * 256);   // Clear all sprite data
  fill(VOICES, 0, 256);         // Silence
  fill(PALETTE16A, 0, 128);     // Black 16-, 4-palletes and COMM

  wr16(SCROLL_X, 0);
  wr16(SCROLL_Y, 0);
  wr(JK_MODE, 0);
  wr(SPR_DISABLE, 0);
  wr(SPR_PAGE, 0);
  wr(IOMODE, 0);
  wr16(BG_COLOR, 0);
  wr16(SAMPLE_L, 0);
  wr16(SAMPLE_R, 0);
  wr16(SCREENSHOT_Y, 0);
  wr(MODULATOR, 64);
  
 
  
  init_ascii();
	
}



void terminal_print(const char* string)
{
	
while(*string != '\0')
{
	terminal_put_char(*string);
	
	string++;
	
}

}

void terminal_put_char(const char character)
{
	int i ;
	
	if(character >= 0x20 && character <= 127) //character is printable
	{
		if(cursor_position_x == 50)
		{
			cursor_position_y++;
			cursor_position_x = 1;
		}
		if(cursor_position_y!=0)
			screen_buffer[(cursor_position_y-1)*64 + cursor_position_x] = character;
		terminal_putchar(character, cursor_position_x, cursor_position_y);
		cursor_position_x++;
		
		
		
		
	}
	else if(character == '\r')
	{
		cursor_position_x = 1;
	}
	else if(character == '\n')
	{
		cursor_position_y++;
	}
	
	if(cursor_position_y >= 37) //Scroll screen
	{
		copy(0, screen_buffer, 64*64);
		
		cursor_position_y = 36;
		
		for(i = 0; i< 63*64; i++)
		{
			screen_buffer[i] = screen_buffer[i+64];
		}
	}
}

void terminal_println(const char* string)
{
	terminal_print(string);
	terminal_print("\r\n");
}

void terminal_putchar(char character, int x, int y) 
{
	
	__wstart((y << 6) + x);
  
	//screen_buffer[x+y] = character;
    spi_transfer(character);
__end();
 
    
}
 

void __start(unsigned int addr) // start an SPI transaction to addr
{
	rFIO0CLR |= 1<<16;  //select slave
	
	spi_transfer(high_byte(addr));
	spi_transfer(low_byte(addr));
}
	
	void __wstart(unsigned int addr) // start an SPI write transaction to addr
{
		__start(0x8000|addr);
	
}
	void wr(unsigned int addr, char v)
	{
			 __wstart(addr);
			spi_transfer(v);
			__end();
	}
void wr16(unsigned int addr, unsigned int v)
{
	  __wstart(addr);
  spi_transfer(low_byte(v));
  spi_transfer(high_byte(v));
  __end();
	
}
void fill(int addr, unsigned char v, unsigned int count)
{
	__wstart(addr);
  while (count--)
    spi_transfer(v);
  __end();
}

void xhide(void)
{
	spi_transfer(low_byte(400));
  spi_transfer(high_byte(400));
  spi_transfer(low_byte(400));
  spi_transfer(high_byte(400));
  //spr++;
}

void __end(void)
{
	
	rFIO0SET |= 1<<16; //release slave
}

static unsigned char stretch[16] = {
  0x00, 0x03, 0x0c, 0x0f,
  0x30, 0x33, 0x3c, 0x3f,
  0xc0, 0xc3, 0xcc, 0xcf,
  0xf0, 0xf3, 0xfc, 0xff
};

void init_ascii(void)
{
	long i;
  for (i = 0; i < 768; i++) {

    unsigned char b = font8x8[i];

    unsigned char h = stretch[b >> 4];
    unsigned char l = stretch[b & 0xf];
    wr(0x1000 + (16 * ' ') + (2 * i), h);
    wr(0x1000 + (16 * ' ') + (2 * i) + 1, l);
  }
  for(i = 0x20; i < 0x80; i++) {
    setpal(4 * i + 0, TRANSPARENT);
    setpal(4 * i + 3, RGB(255,255,255));
  }
  fill(RAM_PIC, ' ', 4096);
}

void setpal(int pal, unsigned int rgb)
{
  wr16(RAM_PAL + (pal << 1), rgb);
}

void copy(unsigned int addr, unsigned char *src, int count)
{
  __wstart(addr);
  while (count--) {
    spi_transfer(*src);
    src++;
  }
  __end();
}
