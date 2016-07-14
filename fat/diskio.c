/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2014        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "diskio.h"		/* FatFs lower layer API */

#include "sd.h"		/* Example: Header file of existing MMC/SDC contorl module */





/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;
	int result;

	switch (pdrv) {
	

	case MMC :
		
		return 0;

	
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;
	int result;

	switch (pdrv) {
	

	case MMC :
		
	
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
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address in LBA */
	UINT count		/* Number of sectors to read */
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
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _USE_WRITE
DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address in LBA */
	UINT count			/* Number of sectors to write */
)
{

	return RES_PARERR;
}
#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;


	return RES_PARERR;
}
#endif
