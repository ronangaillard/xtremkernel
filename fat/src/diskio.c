/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for Petit FatFs (C)ChaN, 2014      */
/*-----------------------------------------------------------------------*/

#include "diskio.h"
#include "sd.h"
#include "types.h"
#include "uart.h"
#include "utilities.h"

BOOL sd_init = FALSE;


extern volatile unsigned char sd_block_buffer[512]; //caller defines buffer
/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                 */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (void)
{
	DSTATUS stat;
	
	send_data_uart0_str("Init of sd card\r\n");

	if(sd_reset() == SD_NO_ERROR)
	{
		stat = 0;
		sd_init = TRUE;
	}
	else
	{
		stat = STA_NOINIT;
	}

	
	return stat;
}



/*-----------------------------------------------------------------------*/
/* Read Partial Sector                                                   */
/*-----------------------------------------------------------------------*/

DRESULT disk_readp (
	BYTE* buff,		/* Pointer to the destination object */
	DWORD sector,	/* Sector number (LBA) */
	UINT offset,	/* Offset in the sector */
	UINT count		/* Byte count (bit15:destination) */
)
{
	
	DRESULT res;
	
	send_data_uart0_str("Reading sector : ");
	send_data_uart0_str(itoa(sector));
	send_data_uart0_str(" ; offset : ");
	send_data_uart0_str(itoa(offset));
	send_data_uart0_str(" ; count : ");
	send_data_uart0_str(itoa(count));
	send_data_uart0_str("\r\n");
	
	/*if(sd_init == FALSE)
		return (DRESULT) RES_NOTRDY;*/
	int i, cnt = 0;
	
	if(sd_read_block(sector) == SD_NO_ERROR)
	{
	
		for(i = offset; i < offset+count; i++)
		{
			
				buff[i - offset] = sd_block_buffer[i];
				send_data_uart0_str(itoa(sd_block_buffer[i]));
				send_data_uart0_str(";");
				cnt++;
			
		}
		
		return (DRESULT)RES_OK;
	}
	else
	{ 
		return (DRESULT)RES_ERROR;
		
	}


	return res;
}



/*-----------------------------------------------------------------------*/
/* Write Partial Sector                                                  */
/*-----------------------------------------------------------------------*/

DRESULT disk_writep (
	const BYTE* buff,		/* Pointer to the data to be written, NULL:Initiate/Finalize write operation */
	DWORD sc		/* Sector number (LBA) or Number of bytes to send */
)
{
	DRESULT res;
	

	if (!buff) {
		if (sc) {

			// Initiate write process

		} else {

			// Finalize write process

		}
	} else {

		// Send data to the disk

	}

	return res;
}

