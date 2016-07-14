#include "uart.h"
#include "constants.h"
#include "types.h"
#include "LPC176x.h"

void send_data_uart0_str( char* buf)
{
	if(buf == NULL || buf[0] == 0)
      return;

   send_data_uart0(buf, string_length(buf));
	
}

int string_length( char* str)
{
	 char* s;

	for (s = str; *s; ++s);
	return (int)(s - str);
	//return 0;
}

void send_data_uart0( char * buf, int size)
{
   int tx_bytes;
    char * ptr = buf;
   int nbytes = size;

   if(buf == NULL || size <= 0)
      return;

   //-- for Tx UART FIFO treshold = 0 -> load = UART_FIFO_SIZE

   

   ptr = buf;
   nbytes = size;

   while(nbytes)
   {
     //-- here - UART Tx FIFO is empty

      if(nbytes > UART_FIFO_SIZE)
         tx_bytes = UART_FIFO_SIZE;
      else
         tx_bytes = nbytes;

      nbytes -= tx_bytes;

      while(tx_bytes--)
         rU0THR = *ptr++;
         
        // THRE bit in the U0LSR
        
        while (!(rU0LSR & 0x20));

      //enable_uart0_tx_interrupt();

      // Wait until UARTO will transmit. After TX end(TX FIFO empty), the TX end
      // interrupt is raised. Inside TX interrupt handler, the TX interrupt
      // will be disabled and semapfore 'semFifoEmptyTxUART0' will be set to signal

      
   }

  
}

void enable_uart0_tx_interrupt(void)
{
   rU0IER |= 2;  //-- Enable Tx int
}

void init_uart0()
{
unsigned int div_val;
   unsigned int cclk;
   unsigned int baudrate;

   //-- Pins

   rPINSEL0 |= (1<<4) |  //-- P0.2 Pins 5:4 = 01 TXD0
               (1<<6);   //-- P0.3 Pins 7:6 = 01 RXD0

   //-- enable access to divisor latch regs

   rU0LCR = LCR_ENABLE_LATCH_ACCESS;

   //-- set divisor for desired baud rate

   cclk     = 96000000; // 88000000;
   baudrate = 115200;

   div_val = (cclk / 16 ) / baudrate;
   rU0DLM = div_val / 256;
   rU0DLL = div_val % 256;

   //-- disable access to divisor latch regs (enable access to xmit/rcv fifos
   //-- and int enable regs)

   rU0LCR = LCR_DISABLE_LATCH_ACCESS;

   //rU0IER = 3;  //-- Enable Rx & Tx int

   rU0IER = 1; //-- Enable Rx int

   rU0FCR = (0x3<<6) | 1;  //-- Int Trigger - 14 bytes, Enable FIFO,Reset Tx FIFO & Rx FIFO

   //-- setup line control reg - disable break transmittion, even parity,
   //-- 1 stop bit, 8 bit chars

   rU0LCR = 0x13;//-- 0b00010011

  //---

   NVIC_EnableIRQ(UART0_IRQn);  //-- It is a safe case global interrupts are not yet enabled
}


