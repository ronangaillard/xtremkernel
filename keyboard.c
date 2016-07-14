#include "LPC176x.h"
#include "utilities.h"
#include "terminal.h"
#include "keyboard.h"
#include "types.h"



extern void EINT3_IRQHandler(void);
BOOL next_charater_is_released = FALSE;
int frame = 0;
int character_entered;

#define BUFFER_SIZE	20
char keyboard_buffer[BUFFER_SIZE];
int last_unread_character = 0;
int place_in_buffer = 0;
int number_of_characters_in_buffer = 0;

#define REALEASED_KEY_CODE	224
void keyboard_init(void)
{

	
	//We use p0.6 (8 on mbed) for DATA
	//We use p0.7 (7 on mbed) for CLOCK
	
	//Set P8 (p0.6) as INPUT with pull-up resistor
	rPINSEL0 &= 0xFFFFCFFF; // use p0.6 as GPIO  (clear bit 12 and 13) (1111 1111 1111 1111 1100 1111 1111 1111)
	rFIO0DIR &= 0xFFFFFFBF; //Set p0.6 as INPUT
	rPINMODE0 &= 0xFFFFCFFF; //Set pull-up on p0.6 (clear bit 12 and 13)
	
	//Set P7 (p0.7) as INPUT with pull-up resistor
	rPINSEL0 &= 0xFFFF3FFF; // use p0.7 as GPIO  (clear bit 14 and 15) (1111 1111 1111 1111 0011 1111 1111 1111)
	rFIO0DIR &= 0xFFFFFF7F; //Set p0.7 as INPUT (‭11111111111111111111111101111111‬)
	rPINMODE0 &= 0xFFFF3FFF; //Set pull-up on p0.7 (clear bit 14 and 15)
	
	rIO0IntEnF |= (1<<6); //interupt 3 on falling edge for pin p0.6
	
	rEXTMODE  |= (1<<3); //EDGE sensitive interupt and not level sensitive interupt
	
	rEXTPOLAR = 0;             // falling edge by default 
	
	NVIC_EnableIRQ(EINT3_IRQn);
	
	 //We clear bits 12 and 13 of PINSEL0 to set pull up resistors
	
}

void EINT3_IRQHandler(void)
{

	rEXTINT |= (1<<3); //clearing interrupt flag 
	rIO0IntClr = (1<<6);
	
	if(rFIO0PIN & (1<<7))
	{
		if(frame!=0 && frame < 9) //Start bit parity bit and stop bit
		character_entered |= (1<<(frame-1));
	}
	
	frame++;
	
	
	if(frame == 11)
	{
		if(character_entered ==REALEASED_KEY_CODE)
		{
			next_charater_is_released = TRUE;
		}
		else
		{
			if(!next_charater_is_released)
			{	
				//terminal_print("Character entered : ");
				//terminal_put_char(ps2_to_ascii(character_entered));
				add_character_in_buffer(ps2_to_ascii(character_entered));
				/*terminal_print(" (");
				terminal_print(itoa(character_entered));
				terminal_println(")");*/
			}
			next_charater_is_released = FALSE;
	}
		frame = 0;
		character_entered = 0;
	
		
		
	}
	
}

unsigned char ps2_to_ascii(unsigned char code)
{
	unsigned char result = '?';
	
	switch(code)
	{  
		case 42: return 'a'; break;
		case 58: return 'z'; break;
		case 72: return 'e'; break;
		case 90: return 'r'; break;
		case 88: return 't'; break;
		case 106: return 'y'; break;
		case 120: return 'u'; break;
		case 134: return 'i'; break;
		case 136: return 'o'; break;
		case 154: return 'p'; break;
		case 56: return 'q'; break;
		case 54: return 's'; break;
		case 70: return 'd'; break;
		case 86: return 'f'; break;
		case 104: return 'g'; break;
		case 102: return 'h'; break;
		case 118: return 'j'; break;
		case 132: return 'k'; break;
		case 150: return 'l'; break;
		case 152: return 'm'; break;
		case 52: return 'w'; break;
		case 68: return 'x'; break;
		case 66: return 'c'; break;
		case 84: return 'v'; break;
		case 100: return 'b'; break;
		case 98: return 'n'; break;
		case 180: return 180; break; //Return key
  
  
	}

return result;
}

void add_character_in_buffer(char character)
{
	
	keyboard_buffer[place_in_buffer] = character;
	
	place_in_buffer++;
	
	if(place_in_buffer == BUFFER_SIZE)
		place_in_buffer = 0;
}

char read_character_in_buffer()
{
	if(place_in_buffer != last_unread_character )
	{
		char char_to_return = keyboard_buffer[last_unread_character];
		last_unread_character++;
		if(last_unread_character >= BUFFER_SIZE)
			last_unread_character = 0;
		return char_to_return;
	}
	else
		return 0;
}
