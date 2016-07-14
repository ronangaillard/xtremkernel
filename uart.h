#ifndef UART_H
#define UART_H

#define  UART_FIFO_SIZE   16
#define  UART0_RX_PAYLOAD_BUF_SIZE   64



#define  LCR_DISABLE_LATCH_ACCESS    0x00000000
#define  LCR_ENABLE_LATCH_ACCESS     0x00000080

void init_uart0(void);
void send_data_uart0_str( char*);
void send_data_uart0( char * buf, int size);
int string_length(char* str);


#endif
