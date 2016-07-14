#include "spi.h"

#include "LPC176x.h"

int spi_transfer(unsigned char data)
{   

	rS0SPDR = data;
   while((rS0SPSR & (1<<7)) == 0);
   
   return rS0SPDR;
	
}

char spi_read()
{
	while (!(rS0SPSR & (1<<2))); //wait for data in RX Fifo 
	return rS0SPDR;
}
