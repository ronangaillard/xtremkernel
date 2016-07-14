#ifndef _LPC176X_H_
#define _LPC176X_H_

/******/

#define  rRSID      (*(volatile unsigned long *) 0x400FC180)
#define  rEXTINT    (*(volatile unsigned long *) 0x400FC140) //-- External Interrupt flag register
#define  rEXTMODE   (*(volatile unsigned long *) 0x400FC148) //-- External Interrupt Mode register

#define  rEXTPOLAR  (*(volatile unsigned long *) 0x400FC14C) //-- External Interrupt Polarity register

#define  rSCS       (*(volatile unsigned long *) 0x400FC1A0) //-- System Controls and Status register

#define  rCLKSRCSEL (*(volatile unsigned long *) 0x400FC10C) //-- Clock Source Select register
#define  rPLL0CON   (*(volatile unsigned long *) 0x400FC080) //-- PLL0 Control register
#define  rPLL0CFG   (*(volatile unsigned long *) 0x400FC084) //-- PLL0 Configuration register
#define  rPLL0STAT  (*(volatile unsigned long *) 0x400FC088) //-- PLL0 Status register
#define  rPLL0FEED  (*(volatile unsigned long *) 0x400FC08C) //-- PLL0 Feed register
#define  rPLL1CON   (*(volatile unsigned long *) 0x400FC0A0) //-- PLL1 Control register
#define  rPLL1CFG   (*(volatile unsigned long *) 0x400FC0A4) //-- PLL1 Configuration register
#define  rPLL1STAT  (*(volatile unsigned long *) 0x400FC0A8) //-- PLL1 Status register
#define  rPLL1FEED  (*(volatile unsigned long *) 0x400FC0AC) //-- PLL1 Feed register
#define  rCCLKCFG   (*(volatile unsigned long *) 0x400FC104) //-- CPU Clock Configuration register
#define  rUSBCLKCFG (*(volatile unsigned long *) 0x400FC108) //-- USB Clock Configuration register
#define  rIRCTRIM   (*(volatile unsigned long *) 0x400FC1A4) //-- IRC Trim Register
#define  rPCLKSEL0  (*(volatile unsigned long *) 0x400FC1A8) //-- Peripheral Clock Selection register 0
#define  rPCLKSEL1  (*(volatile unsigned long *) 0x400FC1AC) //-- Peripheral Clock Selection register 1
#define  rPCON      (*(volatile unsigned long *) 0x400FC0C0) //-- Power Control Register
#define  rPCONP     (*(volatile unsigned long *) 0x400FC0C4) //-- Power Control for Peripherals Register
#define  rCLKOUTCFG (*(volatile unsigned long *) 0x400FC1C8)

#define  rFLASHCFG  (*(volatile unsigned long *) 0x400FC000)

#define  rISER0     (*(volatile unsigned long *) 0xE000E100) //-- Interrupt Set-Enable Register 0 register
#define  rISER1     (*(volatile unsigned long *) 0xE000E104) //-- Interrupt Set-Enable Register 1 register
#define  rICER0     (*(volatile unsigned long *) 0xE000E180) //-- Interrupt Clear-Enable Register 0
#define  rICER1     (*(volatile unsigned long *) 0xE000E184) //-- Interrupt Clear-Enable Register 1 register
#define  rISPR0     (*(volatile unsigned long *) 0xE000E200) //-- Interrupt Set-Pending Register 0 register
#define  rISPR1     (*(volatile unsigned long *) 0xE000E204) //-- Interrupt Set-Pending Register 1 register
#define  rICPR0     (*(volatile unsigned long *) 0xE000E280) //-- Interrupt Clear-Pending Register 0 register
#define  rICPR1     (*(volatile unsigned long *) 0xE000E284) //-- Interrupt Clear-Pending Register 1 register
#define  rIABR0     (*(volatile unsigned long *) 0xE000E300) //-- Interrupt Active Bit Register 0
#define  rIABR1     (*(volatile unsigned long *) 0xE000E304) //-- Interrupt Active Bit Register 1
#define  rIPR0      (*(volatile unsigned long *) 0xE000E400) //-- Interrupt Priority Register 0
#define  rIPR1      (*(volatile unsigned long *) 0xE000E404) //-- Interrupt Priority Register 1
#define  rIPR2      (*(volatile unsigned long *) 0xE000E408) //-- Interrupt Priority Register 2
#define  rIPR3      (*(volatile unsigned long *) 0xE000E40C) //-- Interrupt Priority Register 3
#define  rIPR4      (*(volatile unsigned long *) 0xE000E410) //-- Interrupt Priority Register 4
#define  rIPR5      (*(volatile unsigned long *) 0xE000E414) //-- Interrupt Priority Register 5
#define  rIPR6      (*(volatile unsigned long *) 0xE000E418) //-- Interrupt Priority Register 6
#define  rIPR7      (*(volatile unsigned long *) 0xE000E41C) //-- Interrupt Priority Register 7
#define  rIPR8      (*(volatile unsigned long *) 0xE000E420) //-- Interrupt Priority Register 8
#define  rSTIR      (*(volatile unsigned long *) 0xE000EF00) //-- Software Trigger Interrupt Register

#define  rPINSEL0   (*(volatile unsigned long *) 0x4002C000) //-- Pin Function Select register  0
#define  rPINSEL1   (*(volatile unsigned long *) 0x4002C004) //-- Pin Function Select Register  1
#define  rPINSEL2   (*(volatile unsigned long *) 0x4002C008) //-- Pin Function Select register  2
#define  rPINSEL3   (*(volatile unsigned long *) 0x4002C00C) //-- Pin Function Select Register  3
#define  rPINSEL4   (*(volatile unsigned long *) 0x4002C010) //-- Pin Function Select Register  4
#define  rPINSEL7   (*(volatile unsigned long *) 0x4002C01C) //-- Pin Function Select Register  7
#define  rPINSEL9   (*(volatile unsigned long *) 0x4002C024) //-- Pin Function Select Register  9
#define  rPINSEL10  (*(volatile unsigned long *) 0x4002C028) //-- Pin Function Select Register 10

#define  rPINMODE0  (*(volatile unsigned long *) 0x4002C040) //-- Pin Mode select register 0
#define  rPINMODE1  (*(volatile unsigned long *) 0x4002C044) //-- Pin Mode select register 1
#define  rPINMODE2  (*(volatile unsigned long *) 0x4002C048) //-- Pin Mode select register 2
#define  rPINMODE3  (*(volatile unsigned long *) 0x4002C04C) //-- Pin Mode select register 3
#define  rPINMODE4  (*(volatile unsigned long *) 0x4002C050) //-- Pin Mode select register 4
#define  rPINMODE7  (*(volatile unsigned long *) 0x4002C05C) //-- Pin Mode select register 7
#define  rPINMODE9  (*(volatile unsigned long *) 0x4002C064) //-- Pin Mode select register 9

#define  rPINMODE_OD0  (*(volatile unsigned long *) 0x4002C068) //-- Open Drain Pin Mode select register 0
#define  rPINMODE_OD1  (*(volatile unsigned long *) 0x4002C06C) //-- Open Drain Pin Mode select register 1
#define  rPINMODE_OD2  (*(volatile unsigned long *) 0x4002C070) //-- Open Drain Pin Mode select register 2
#define  rPINMODE_OD3  (*(volatile unsigned long *) 0x4002C074) //-- Open Drain Pin Mode select register 3
#define  rPINMODE_OD4  (*(volatile unsigned long *) 0x4002C078) //-- Open Drain Pin Mode select register 4

#define  rI2CPADCFG  (*(volatile unsigned long *)   0x4002C07C) //-- I2C Pin Configuration register

//----  GPIO port Direction registers

#define  rFIO0DIR   (*(volatile unsigned long *)  0x2009C000)
#define  rFIO0DIR0  (*(volatile unsigned char *)  0x2009C000)
#define  rFIO0DIR1  (*(volatile unsigned char *)  0x2009C001)
#define  rFIO0DIR2  (*(volatile unsigned char *)  0x2009C002)
#define  rFIO0DIR3  (*(volatile unsigned char *)  0x2009C003)
#define  rFIO0DIRL  (*(volatile unsigned short *) 0x2009C000)
#define  rFIO0DIRU  (*(volatile unsigned short *) 0x2009C002)
#define  rFIO0DIRH  rFIO0DIRU

#define  rFIO1DIR   (*(volatile unsigned long *)  0x2009C020)
#define  rFIO1DIR0  (*(volatile unsigned char *)  0x2009C020)
#define  rFIO1DIR1  (*(volatile unsigned char *)  0x2009C021)
#define  rFIO1DIR2  (*(volatile unsigned char *)  0x2009C022)
#define  rFIO1DIR3  (*(volatile unsigned char *)  0x2009C023)
#define  rFIO1DIRL  (*(volatile unsigned short *) 0x2009C020)
#define  rFIO1DIRU  (*(volatile unsigned short *) 0x2009C022)
#define  rFIO1DIRH  rFIO1DIRU

#define  rFIO2DIR   (*(volatile unsigned long *)  0x2009C040)
#define  rFIO2DIR0  (*(volatile unsigned char *)  0x2009C040)
#define  rFIO2DIR1  (*(volatile unsigned char *)  0x2009C041)
#define  rFIO2DIR2  (*(volatile unsigned char *)  0x2009C042)
#define  rFIO2DIR3  (*(volatile unsigned char *)  0x2009C043)
#define  rFIO2DIRL  (*(volatile unsigned short *) 0x2009C040)
#define  rFIO2DIRU  (*(volatile unsigned short *) 0x2009C042)
#define  rFIO2DIRH  rFIO2DIRU

#define  rFIO3DIR   (*(volatile unsigned long *)  0x2009C060)
#define  rFIO3DIR0  (*(volatile unsigned char *)  0x2009C060)
#define  rFIO3DIR1  (*(volatile unsigned char *)  0x2009C061)
#define  rFIO3DIR2  (*(volatile unsigned char *)  0x2009C062)
#define  rFIO3DIR3  (*(volatile unsigned char *)  0x2009C063)
#define  rFIO3DIRL  (*(volatile unsigned short *) 0x2009C060)
#define  rFIO3DIRU  (*(volatile unsigned short *) 0x2009C062)
#define  rFIO3DIRH  rFIO3DIRU

#define  rFIO4DIR   (*(volatile unsigned long *)  0x2009C080)
#define  rFIO4DIR0  (*(volatile unsigned char *)  0x2009C080)
#define  rFIO4DIR1  (*(volatile unsigned char *)  0x2009C081)
#define  rFIO4DIR2  (*(volatile unsigned char *)  0x2009C082)
#define  rFIO4DIR3  (*(volatile unsigned char *)  0x2009C083)
#define  rFIO4DIRL  (*(volatile unsigned short *) 0x2009C080)
#define  rFIO4DIRU  (*(volatile unsigned short *) 0x2009C082)
#define  rFIO4DIRH  rFIO4DIRU

//---- Fast GPIO port Mask register

#define 	rFIO0MASK   (*(volatile unsigned long *)  0x2009C010)
#define 	rFIO0MASK0  (*(volatile unsigned char *)  0x2009C010)
#define 	rFIO0MASK1  (*(volatile unsigned char *)  0x2009C011)
#define 	rFIO0MASK2  (*(volatile unsigned char *)  0x2009C012)
#define 	rFIO0MASK3  (*(volatile unsigned char *)  0x2009C013)
#define 	rFIO0MASKL  (*(volatile unsigned short *) 0x2009C010)
#define 	rFIO0MASKU  (*(volatile unsigned short *) 0x2009C012)
#define 	rFIO0MASKH  rFIO0MASKU

#define 	rFIO1MASK   (*(volatile unsigned long *)  0x2009C030)
#define 	rFIO1MASK0  (*(volatile unsigned char *)  0x2009C030)
#define 	rFIO1MASK1  (*(volatile unsigned char *)  0x2009C031)
#define 	rFIO1MASK2  (*(volatile unsigned char *)  0x2009C032)
#define 	rFIO1MASK3  (*(volatile unsigned char *)  0x2009C033)
#define 	rFIO1MASKL  (*(volatile unsigned short *) 0x2009C030)
#define 	rFIO1MASKU  (*(volatile unsigned short *) 0x2009C032)
#define 	rFIO1MASKH  rFIO1MASKU

#define 	rFIO2MASK   (*(volatile unsigned long *)  0x2009C050)
#define 	rFIO2MASK0  (*(volatile unsigned char *)  0x2009C050)
#define 	rFIO2MASK1  (*(volatile unsigned char *)  0x2009C051)
#define 	rFIO2MASK2  (*(volatile unsigned char *)  0x2009C052)
#define 	rFIO2MASK3  (*(volatile unsigned char *)  0x2009C053)
#define 	rFIO2MASKL  (*(volatile unsigned short *) 0x2009C050)
#define 	rFIO2MASKU  (*(volatile unsigned short *) 0x2009C052)
#define 	rFIO2MASKH  rFIO2MASKU

#define 	rFIO3MASK   (*(volatile unsigned long *)  0x2009C070)
#define 	rFIO3MASK0  (*(volatile unsigned char *)  0x2009C070)
#define 	rFIO3MASK1  (*(volatile unsigned char *)  0x2009C071)
#define 	rFIO3MASK2  (*(volatile unsigned char *)  0x2009C072)
#define 	rFIO3MASK3  (*(volatile unsigned char *)  0x2009C073)
#define 	rFIO3MASKL  (*(volatile unsigned short *) 0x2009C070)
#define 	rFIO3MASKU  (*(volatile unsigned short *) 0x2009C072)
#define 	rFIO3MASKH  rFIO3MASKU

#define 	rFIO4MASK   (*(volatile unsigned long *)  0x2009C090)
#define 	rFIO4MASK0  (*(volatile unsigned char *)  0x2009C090)
#define 	rFIO4MASK1  (*(volatile unsigned char *)  0x2009C091)
#define 	rFIO4MASK2  (*(volatile unsigned char *)  0x2009C092)
#define 	rFIO4MASK3  (*(volatile unsigned char *)  0x2009C093)
#define 	rFIO4MASKL  (*(volatile unsigned short *) 0x2009C090)
#define 	rFIO4MASKU  (*(volatile unsigned short *) 0x2009C092)
#define 	rFIO4MASKH  rFIO4MASKU

//---- GPIO port Pin value register

#define  rFIO0PIN   (*(volatile unsigned long *)  0x2009C014)
#define  rFIO0PIN0  (*(volatile unsigned char *)  0x2009C014)
#define  rFIO0PIN1  (*(volatile unsigned char *)  0x2009C015)
#define  rFIO0PIN2  (*(volatile unsigned char *)  0x2009C016)
#define  rFIO0PIN3  (*(volatile unsigned char *)  0x2009C017)
#define  rFIO0PINL  (*(volatile unsigned short *) 0x2009C014)
#define  rFIO0PINU  (*(volatile unsigned short *) 0x2009C016)
#define  rFIO0PINH  rFIO0PINU

#define  rFIO1PIN   (*(volatile unsigned long *)  0x2009C034)
#define  rFIO1PIN0  (*(volatile unsigned char *)  0x2009C034)
#define  rFIO1PIN1  (*(volatile unsigned char *)  0x2009C035)
#define  rFIO1PIN2  (*(volatile unsigned char *)  0x2009C036)
#define  rFIO1PIN3  (*(volatile unsigned char *)  0x2009C037)
#define  rFIO1PINL  (*(volatile unsigned short *) 0x2009C034)
#define  rFIO1PINU  (*(volatile unsigned short *) 0x2009C036)
#define  rFIO1PINH  rFIO1PINU

#define  rFIO2PIN   (*(volatile unsigned long *)  0x2009C054)
#define  rFIO2PIN0  (*(volatile unsigned char *)  0x2009C054)
#define  rFIO2PIN1  (*(volatile unsigned char *)  0x2009C055)
#define  rFIO2PIN2  (*(volatile unsigned char *)  0x2009C056)
#define  rFIO2PIN3  (*(volatile unsigned char *)  0x2009C057)
#define  rFIO2PINL  (*(volatile unsigned short *) 0x2009C054)
#define  rFIO2PINU  (*(volatile unsigned short *) 0x2009C056)
#define  rFIO2PINH  rFIO2PINU

#define  rFIO3PIN   (*(volatile unsigned long *)  0x2009C074)
#define  rFIO3PIN0  (*(volatile unsigned char *)  0x2009C074)
#define  rFIO3PIN1  (*(volatile unsigned char *)  0x2009C075)
#define  rFIO3PIN2  (*(volatile unsigned char *)  0x2009C076)
#define  rFIO3PIN3  (*(volatile unsigned char *)  0x2009C077)
#define  rFIO3PINL  (*(volatile unsigned short *) 0x2009C074)
#define  rFIO3PINU  (*(volatile unsigned short *) 0x2009C076)
#define  rFIO3PINH  rFIO3PINU

#define  rFIO4PIN   (*(volatile unsigned long *)  0x2009C094)
#define  rFIO4PIN0  (*(volatile unsigned char *)  0x2009C094)
#define  rFIO4PIN1  (*(volatile unsigned char *)  0x2009C095)
#define  rFIO4PIN2  (*(volatile unsigned char *)  0x2009C096)
#define  rFIO4PIN3  (*(volatile unsigned char *)  0x2009C097)
#define  rFIO4PINL  (*(volatile unsigned short *) 0x2009C094)
#define  rFIO4PINU  (*(volatile unsigned short *) 0x2009C096)
#define  rFIO4PINH  rFIO4PINU

//---- GPIO port output Set registers

#define  rFIO0SET   (*(volatile unsigned long *)  0x2009C018)
#define  rFIO0SET0  (*(volatile unsigned char *)  0x2009C018)
#define  rFIO0SET1  (*(volatile unsigned char *)  0x2009C019)
#define  rFIO0SET2  (*(volatile unsigned char *)  0x2009C01A)
#define  rFIO0SET3  (*(volatile unsigned char *)  0x2009C01B)
#define  rFIO0SETL  (*(volatile unsigned short *) 0x2009C018)
#define  rFIO0SETU  (*(volatile unsigned short *) 0x2009C01A)
#define  rFIO0SETH  rFIO0SETU

#define  rFIO1SET   (*(volatile unsigned long *)  0x2009C038)
#define  rFIO1SET0  (*(volatile unsigned char *)  0x2009C038)
#define  rFIO1SET1  (*(volatile unsigned char *)  0x2009C039)
#define  rFIO1SET2  (*(volatile unsigned char *)  0x2009C03A)
#define  rFIO1SET3  (*(volatile unsigned char *)  0x2009C03B)
#define  rFIO1SETL  (*(volatile unsigned short *) 0x2009C038)
#define  rFIO1SETU  (*(volatile unsigned short *) 0x2009C03A)
#define  rFIO1SETH  rFIO1SETU

#define  rFIO2SET   (*(volatile unsigned long *)  0x2009C058)
#define  rFIO2SET0  (*(volatile unsigned char *)  0x2009C058)
#define  rFIO2SET1  (*(volatile unsigned char *)  0x2009C059)
#define  rFIO2SET2  (*(volatile unsigned char *)  0x2009C05A)
#define  rFIO2SET3  (*(volatile unsigned char *)  0x2009C05B)
#define  rFIO2SETL  (*(volatile unsigned short *) 0x2009C058)
#define  rFIO2SETU  (*(volatile unsigned short *) 0x2009C05A)
#define  rFIO2SETH  rFIO2SETU

#define  rFIO3SET   (*(volatile unsigned long *)  0x2009C078)
#define  rFIO3SET0  (*(volatile unsigned char *)  0x2009C078)
#define  rFIO3SET1  (*(volatile unsigned char *)  0x2009C079)
#define  rFIO3SET2  (*(volatile unsigned char *)  0x2009C07A)
#define  rFIO3SET3  (*(volatile unsigned char *)  0x2009C07B)
#define  rFIO3SETL  (*(volatile unsigned short *) 0x2009C078)
#define  rFIO3SETU  (*(volatile unsigned short *) 0x2009C07A)
#define  rFIO3SETH  rFIO3SETU

#define  rFIO4SET   (*(volatile unsigned long *)  0x2009C098)
#define  rFIO4SET0  (*(volatile unsigned char *)  0x2009C098)
#define  rFIO4SET1  (*(volatile unsigned char *)  0x2009C099)
#define  rFIO4SET2  (*(volatile unsigned char *)  0x2009C09A)
#define  rFIO4SET3  (*(volatile unsigned char *)  0x2009C09B)
#define  rFIO4SETL  (*(volatile unsigned short *) 0x2009C098)
#define  rFIO4SETU  (*(volatile unsigned short *) 0x2009C09A)
#define  rFIO4SETH  rFIO4SETU

//---- GPIO port output Clear register

#define  rFIO0CLR   (*(volatile unsigned long *)  0x2009C01C)
#define  rFIO0CLR0  (*(volatile unsigned char *)  0x2009C01C)
#define  rFIO0CLR1  (*(volatile unsigned char *)  0x2009C01D)
#define  rFIO0CLR2  (*(volatile unsigned char *)  0x2009C01E)
#define  rFIO0CLR3  (*(volatile unsigned char *)  0x2009C01F)
#define  rFIO0CLRL  (*(volatile unsigned short *) 0x2009C01C)
#define  rFIO0CLRU  (*(volatile unsigned short *) 0x2009C01E)
#define  rFIO0CLRH  rFIO0CLRU

#define  rFIO1CLR   (*(volatile unsigned long *)  0x2009C03C)
#define  rFIO1CLR0  (*(volatile unsigned char *)  0x2009C03C)
#define  rFIO1CLR1  (*(volatile unsigned char *)  0x2009C03D)
#define  rFIO1CLR2  (*(volatile unsigned char *)  0x2009C03E)
#define  rFIO1CLR3  (*(volatile unsigned char *)  0x2009C03F)
#define  rFIO1CLRL  (*(volatile unsigned short *) 0x2009C03C)
#define  rFIO1CLRU  (*(volatile unsigned short *) 0x2009C03E)
#define  rFIO1CLRH  rFIO1CLRU

#define  rFIO2CLR   (*(volatile unsigned long *)  0x2009C05C)
#define  rFIO2CLR0  (*(volatile unsigned char *)  0x2009C05C)
#define  rFIO2CLR1  (*(volatile unsigned char *)  0x2009C05D)
#define  rFIO2CLR2  (*(volatile unsigned char *)  0x2009C05E)
#define  rFIO2CLR3  (*(volatile unsigned char *)  0x2009C05F)
#define  rFIO2CLRL  (*(volatile unsigned short *) 0x2009C05C)
#define  rFIO2CLRU  (*(volatile unsigned short *) 0x2009C05E)
#define  rFIO2CLRH  rFIO2CLRU

#define  rFIO3CLR   (*(volatile unsigned long *)  0x2009C07C)
#define  rFIO3CLR0  (*(volatile unsigned char *)  0x2009C07C)
#define  rFIO3CLR1  (*(volatile unsigned char *)  0x2009C07D)
#define  rFIO3CLR2  (*(volatile unsigned char *)  0x2009C07E)
#define  rFIO3CLR3  (*(volatile unsigned char *)  0x2009C07F)
#define  rFIO3CLRL  (*(volatile unsigned short *) 0x2009C07C)
#define  rFIO3CLRU  (*(volatile unsigned short *) 0x2009C07E)
#define  rFIO3CLRH  rFIO3CLRU

#define  rFIO4CLR   (*(volatile unsigned long *)  0x2009C09C)
#define  rFIO4CLR0  (*(volatile unsigned char *)  0x2009C09C)
#define  rFIO4CLR1  (*(volatile unsigned char *)  0x2009C09D)
#define  rFIO4CLR2  (*(volatile unsigned char *)  0x2009C09E)
#define  rFIO4CLR3  (*(volatile unsigned char *)  0x2009C09F)
#define  rFIO4CLRL  (*(volatile unsigned short *) 0x2009C09C)
#define  rFIO4CLRU  (*(volatile unsigned short *) 0x2009C09E)
#define  rFIO4CLRH  rFIO4CLRU

//---- GPIO Interrupt

#define 	rIOIntStatus  (*(volatile unsigned long *)  0x40028080) //-- GPIO overall Interrupt Status register
#define 	rIO0IntEnR    (*(volatile unsigned long *)  0x40028090) //-- GPIO Interrupt Enable for port 0 Rising Edge
#define 	rIO2IntEnR    (*(volatile unsigned long *)  0x400280B0) //-- GPIO Interrupt Enable for port 2 Rising Edge
#define 	rIO0IntEnF    (*(volatile unsigned long *)  0x40028094) //-- GPIO Interrupt Enable for port 0 Falling Edge
#define 	rIO2IntEnF    (*(volatile unsigned long *)  0x400280B4) //-- GPIO Interrupt Enable for port 2 Falling Edge
#define 	rIO0IntStatR  (*(volatile unsigned long *)  0x40028084) //-- GPIO Interrupt Status for port 0 Rising Edge Interrupt
#define 	rIO2IntStatR  (*(volatile unsigned long *)  0x400280A4) //-- GPIO Interrupt Status for port 2 Rising Edge Interrupt
#define 	rIO0IntStatF  (*(volatile unsigned long *)  0x40028088) //-- GPIO Interrupt Status for port 0 Falling Edge Interrupt
#define 	rIO2IntStatF  (*(volatile unsigned long *)  0x400280A8) //-- GPIO Interrupt Status for port 2 Falling Edge Interrupt
#define 	rIO0IntClr    (*(volatile unsigned long *)  0x4002808C) //-- GPIO Interrupt Clear register for port 0
#define 	rIO2IntClr    (*(volatile unsigned long *)  0x400280AC) //-- GPIO Interrupt Clear register for port 0

//----  Ethernet MAC

#define 	rMAC1         (*(volatile unsigned long *)  0x50000000) //-- MAC Configuration Register 1
#define 	rMAC2         (*(volatile unsigned long *)  0x50000004) //-- MAC Configuration Register 2
#define 	rIPGT         (*(volatile unsigned long *)  0x50000008) //-- Back-to-Back Inter-Packet-Gap Register
#define 	rIPGR         (*(volatile unsigned long *)  0x5000000C) //-- Non Back-to-Back Inter-Packet-Gap Register
#define 	rCLRT         (*(volatile unsigned long *)  0x50000010) //-- Collision Window / Retry Register
#define 	rMAXF         (*(volatile unsigned long *)  0x50000014) //-- Maximum Frame Register
#define 	rSUPP         (*(volatile unsigned long *)  0x50000018) //-- PHY Support Register
#define 	rTEST         (*(volatile unsigned long *)  0x5000001C) //-- Test Register
#define 	rMCFG         (*(volatile unsigned long *)  0x50000020) //-- MII Mgmt Configuration Register
#define 	rMCMD         (*(volatile unsigned long *)  0x50000024) //-- MII Mgmt Command Register
#define 	rMADR         (*(volatile unsigned long *)  0x50000028) //-- MII Mgmt Address Register
#define 	rMWTD         (*(volatile unsigned long *)  0x5000002C) //-- MII Mgmt Write Data Register
#define 	rMRDD         (*(volatile unsigned long *)  0x50000030) //-- MII Mgmt Read Data Register
#define 	rMIND         (*(volatile unsigned long *)  0x50000034) //-- MII Mgmt Indicators Register
#define 	rSA0          (*(volatile unsigned long *)  0x50000040) //-- Station Address 0 Register
#define 	rSA1          (*(volatile unsigned long *)  0x50000044) //-- Station Address 1 Register
#define 	rSA2          (*(volatile unsigned long *)  0x50000048) //-- Station Address 2 Register

#define 	rCommand             (*(volatile unsigned long *)  0x50000100) //-- Command Register
#define 	rStatus              (*(volatile unsigned long *)  0x50000104) //-- Status Register
#define 	rRxDescriptor        (*(volatile unsigned long *)  0x50000108) //-- Receive Descriptor Base Address Register
#define 	rRxStatus            (*(volatile unsigned long *)  0x5000010C) //-- Receive Status Base Address Register
#define 	rRxDescriptorNumber  (*(volatile unsigned long *)  0x50000110) //-- Receive Number of Descriptors Register
#define 	rRxProduceIndex      (*(volatile unsigned long *)  0x50000114) //-- Receive Produce Index Register
#define 	rRxConsumeIndex      (*(volatile unsigned long *)  0x50000118) //-- Receive Consume Index Register
#define 	rTxDescriptor        (*(volatile unsigned long *)  0x5000011C) //-- Transmit Descriptor Base Address Register
#define 	rTxStatus            (*(volatile unsigned long *)  0x50000120) //-- Transmit Status Base Address Register
#define 	rTxDescriptorNumber  (*(volatile unsigned long *)  0x50000124) //-- Transmit Number of Descriptors Register
#define 	rTxProduceIndex      (*(volatile unsigned long *)  0x50000128) //-- Transmit Produce Index Register
#define 	rTxConsumeIndex      (*(volatile unsigned long *)  0x5000012C) //-- Transmit Consume Index Register
#define 	rTSV0                (*(volatile unsigned long *)  0x50000158) //-- Transmit Status Vector 0 Register
#define 	rTSV1                (*(volatile unsigned long *)  0x5000015C) //-- Transmit Status Vector 1 Register
#define 	rRSV                 (*(volatile unsigned long *)  0x50000160) //-- Receive Status Vector Register
#define 	rFlowControlCounter  (*(volatile unsigned long *)  0x50000170) //-- Flow Control Counter Register
#define 	rFlowControlStatus   (*(volatile unsigned long *)  0x50000174) //-- Flow Control Status Register
#define 	rRxFilterCtrl        (*(volatile unsigned long *)  0x50000200) //-- Receive Filter Control Register
#define 	rRxFilterWoLStatus   (*(volatile unsigned long *)  0x50000204) //-- Receive Filter WoL Status Register
#define 	rRxFilterWoLClear    (*(volatile unsigned long *)  0x50000208) //-- Receive Filter WoL Clear Register
#define 	rHashFilterL         (*(volatile unsigned long *)  0x50000210) //-- Hash Filter Table LSBs Register
#define 	rHashFilterH         (*(volatile unsigned long *)  0x50000214) //-- Hash Filter Table MSBs Register
#define 	rIntStatus           (*(volatile unsigned long *)  0x50000FE0) //-- Interrupt Status Register
#define 	rIntEnable           (*(volatile unsigned long *)  0x50000FE4) //-- Interrupt Enable Register
#define 	rIntClear            (*(volatile unsigned long *)  0x50000FE8) //-- Interrupt Clear Register
#define 	rIntSet              (*(volatile unsigned long *)  0x50000FEC) //-- Interrupt Set Register
#define 	rPowerDown           (*(volatile unsigned long *)  0x50000FF4) //-- Power-Down Register

//----  USB

#define 	rUSBClkCtrl       (*(volatile unsigned long *)  0x5000CFF4) //-- USB Clock Control register
#define 	rUSBClkSt         (*(volatile unsigned long *)  0x5000CFF8) //-- USB Clock Status register
#define 	rUSBIntSt         (*(volatile unsigned long *)  0x5000C1C0) //-- USB Interrupt Status register
#define 	rUSBDevIntSt      (*(volatile unsigned long *)  0x5000C200) //-- USB Device Interrupt Status register
#define 	rUSBDevIntEn      (*(volatile unsigned long *)  0x5000C204) //-- USB Device Interrupt Enable register
#define 	rUSBDevIntClr     (*(volatile unsigned long *)  0x5000C208) //-- USB Device Interrupt Clear register
#define 	rUSBDevIntSet     (*(volatile unsigned long *)  0x5000C20C) //-- USB Device Interrupt Set register
#define 	rUSBDevIntPri     (*(volatile unsigned long *)  0x5000C22C) //-- USB Device Interrupt Priority register
#define 	rUSBEpIntSt       (*(volatile unsigned long *)  0x5000C230) //-- USB Endpoint Interrupt Status register
#define 	rUSBEpIntEn       (*(volatile unsigned long *)  0x5000C234) //-- USB Endpoint Interrupt Enable register
#define 	rUSBEpIntClr      (*(volatile unsigned long *)  0x5000C238) //-- USB Endpoint Interrupt Clear register
#define 	rUSBEpIntSet      (*(volatile unsigned long *)  0x5000C23C) //-- USB Endpoint Interrupt Set register
#define 	rUSBEpIntPri      (*(volatile unsigned long *)  0x5000C240) //-- USB Endpoint Interrupt Priority register
#define 	rUSBReEp          (*(volatile unsigned long *)  0x5000C244) //-- USB Realize Endpoint register
#define 	rUSBEpIn          (*(volatile unsigned long *)  0x5000C248) //-- USB Endpoint Index register
#define 	rUSBMaxPSize      (*(volatile unsigned long *)  0x5000C24C) //-- USB MaxPacketSize register
#define 	rUSBRxData        (*(volatile unsigned long *)  0x5000C218) //-- USB Receive Data register
#define 	rUSBRxPLen        (*(volatile unsigned long *)  0x5000C220) //-- USB Receive Packet Length register
#define 	rUSBTxData        (*(volatile unsigned long *)  0x5000C21C) //-- USB Transmit Data register
#define 	rUSBTxPLen        (*(volatile unsigned long *)  0x5000C224) //-- USB Transmit Packet Length register
#define 	rUSBCtrl          (*(volatile unsigned long *)  0x5000C228) //-- USB Control register
#define 	rUSBCmdCode       (*(volatile unsigned long *)  0x5000C210) //-- USB Command Code register
#define 	rUSBCmdData       (*(volatile unsigned long *)  0x5000C214) //-- USB Command Data register
#define 	rUSBDMARSt        (*(volatile unsigned long *)  0x5000C250) //-- USB DMA Request Status register
#define 	rUSBDMARClr       (*(volatile unsigned long *)  0x5000C254) //-- USB DMA Request Clear register
#define 	rUSBDMARSet       (*(volatile unsigned long *)  0x5000C258) //-- USB DMA Request Set register
#define 	rUSBUDCAH         (*(volatile unsigned long *)  0x5000C280) //-- USB UDCA Head register
#define 	rUSBEpDMASt       (*(volatile unsigned long *)  0x5000C284) //-- USB EP DMA Status register
#define 	rUSBEpDMAEn       (*(volatile unsigned long *)  0x5000C288) //-- USB EP DMA Enable register
#define 	rUSBEpDMADis      (*(volatile unsigned long *)  0x5000C28C) //-- USB EP DMA Disable register
#define 	rUSBDMAIntSt      (*(volatile unsigned long *)  0x5000C290) //-- USB DMA Interrupt Status register
#define 	rUSBDMAIntEn      (*(volatile unsigned long *)  0x5000C294) //-- USB DMA Interrupt Enable register
#define 	rUSBEoTIntSt      (*(volatile unsigned long *)  0x5000C2A0) //-- USB End of Transfer Interrupt Status register
#define 	rUSBEoTIntClr     (*(volatile unsigned long *)  0x5000C2A4) //-- USB End of Transfer Interrupt Clear register
#define 	rUSBEoTIntSet     (*(volatile unsigned long *)  0x5000C2A8) //-- USB End of Transfer Interrupt Set register
#define 	rUSBNDDRIntSt     (*(volatile unsigned long *)  0x5000C2AC) //-- USB New DD Request Interrupt Status register
#define 	rUSBNDDRIntClr    (*(volatile unsigned long *)  0x5000C2B0) //-- USB New DD Request Interrupt Clear register
#define 	rUSBNDDRIntSet    (*(volatile unsigned long *)  0x5000C2B4) //-- USB New DD Request Interrupt Set register
#define 	rUSBSysErrIntSt   (*(volatile unsigned long *)  0x5000C2B8) //-- USB System Error Interrupt Status register
#define 	rUSBSysErrIntClr  (*(volatile unsigned long *)  0x5000C2BC) //-- USB System Error Interrupt Clear register
#define 	rUSBSysErrIntSet  (*(volatile unsigned long *)  0x5000C2C0) //-- USB System Error Interrupt Set register

#define 	rOTGIntSt    (*(volatile unsigned long *)  0x5000C100) //-- OTG Interrupt Status Register
#define 	rOTGIntEn    (*(volatile unsigned long *)  0x5000C104) //-- OTG Interrupt Enable Register
//--- !!!!
#define 	rOTGIntSet   (*(volatile unsigned long *)  0x5000C108) //-- OTG Interrupt Set Register
//--------------
#define 	rOTGIntClr   (*(volatile unsigned long *)  0x5000C10C) //-- OTG Interrupt Clear Register
#define 	rOTGStCtrl   (*(volatile unsigned long *)  0x5000C110) //-- OTG Status and Control Register
#define 	rOTGTmr      (*(volatile unsigned long *)  0x5000C114) //-- OTG Timer Register
#define 	rOTGClkCtrl  (*(volatile unsigned long *)  0x5000CFF4) //-- OTG Clock Control Register
#define 	rOTGClkSt    (*(volatile unsigned long *)  0x5000CFF8) //-- OTG Clock Status Register
#define 	rI2C_RX      (*(volatile unsigned long *)  0x5000C300) //-- I2C Receive Register
#define 	rI2C_TX      (*(volatile unsigned long *)  0x5000C300) //-- I2C Transmit Register
#define 	rI2C_STS     (*(volatile unsigned long *)  0x5000C304) //-- I2C Status Register
#define 	rI2C_CTL     (*(volatile unsigned long *)  0x5000C308) //-- I2C Control Register
#define 	rI2C_CLKHI   (*(volatile unsigned long *)  0x5000C30C) //-- I2C Clock High Register
#define 	rI2C_CLKLO   (*(volatile unsigned long *)  0x5000C310) //-- I2C Clock Low Register

//----  UART0, UART2, UART3

#define 	rU0RBR      (*(volatile unsigned long *)  0x4000C000) //-- UARTn Receiver Buffer Register
#define 	rU0THR      (*(volatile unsigned long *)  0x4000C000) //-- UARTn Transmit Holding Register
#define 	rU0DLL      (*(volatile unsigned long *)  0x4000C000) //-- UARTn Divisor Latch LSB register
#define 	rU0DLM      (*(volatile unsigned long *)  0x4000C004) //-- Latch MSB register
#define 	rU0IER      (*(volatile unsigned long *)  0x4000C004) //-- UARTn Interrupt Enable Register
#define 	rU0IIR      (*(volatile unsigned long *)  0x4000C008) //-- UARTn Interrupt Identification Register
#define 	rU0FCR      (*(volatile unsigned long *)  0x4000C008) //-- UARTn FIFO Control Register
#define 	rU0LCR      (*(volatile unsigned long *)  0x4000C00C) //-- UARTn Line Control Register
#define 	rU0LSR      (*(volatile unsigned long *)  0x4000C014) //-- UARTn Line Status Register
#define 	rU0SCR      (*(volatile unsigned long *)  0x4000C01C) //-- UARTn Scratch Pad Register
#define 	rU0ACR      (*(volatile unsigned long *)  0x4000C020) //-- UARTn Auto-baud Control Register
#define 	rU0ICR      (*(volatile unsigned long *)  0x4000C024) //-- UARTn IrDA Control Register
#define 	rU0FDR      (*(volatile unsigned long *)  0x4000C028) //-- UARTn Fractional Divider Register
#define 	rU0TER      (*(volatile unsigned long *)  0x4000C030) //-- UARTn Transmit Enable Register
#define 	rU0FIFOLVL  (*(volatile unsigned long *)  0x4000C058) //-- UARTn FIFO Level register

#define 	rU2RBR      (*(volatile unsigned long *)  0x40098000) //-- UARTn Receiver Buffer Register
#define 	rU2THR      (*(volatile unsigned long *)  0x40098000) //-- UARTn Transmit Holding Register
#define 	rU2DLL      (*(volatile unsigned long *)  0x40098000) //-- UARTn Divisor Latch LSB register
#define 	rU2DLM      (*(volatile unsigned long *)  0x40098004) //-- Latch MSB register
#define 	rU2IER      (*(volatile unsigned long *)  0x40098004) //-- UARTn Interrupt Enable Register
#define 	rU2IIR      (*(volatile unsigned long *)  0x40098008) //-- UARTn Interrupt Identification Register
#define 	rU2FCR      (*(volatile unsigned long *)  0x40098008) //-- UARTn FIFO Control Register
#define 	rU2LCR      (*(volatile unsigned long *)  0x4009800C) //-- UARTn Line Control Register
#define 	rU2LSR      (*(volatile unsigned long *)  0x40098014) //-- UARTn Line Status Register
#define 	rU2SCR      (*(volatile unsigned long *)  0x4009801C) //-- UARTn Scratch Pad Register
#define 	rU2ACR      (*(volatile unsigned long *)  0x40098020) //-- UARTn Auto-baud Control Register
#define 	rU2ICR      (*(volatile unsigned long *)  0x40098024) //-- UARTn IrDA Control Register
#define 	rU2FDR      (*(volatile unsigned long *)  0x40098028) //-- UARTn Fractional Divider Register
#define 	rU2TER      (*(volatile unsigned long *)  0x40098030) //-- UARTn Transmit Enable Register
#define 	rU2FIFOLVL  (*(volatile unsigned long *)  0x40098058) //-- UARTn FIFO Level register

#define 	rU3RBR      (*(volatile unsigned long *)  0x4009C000) //-- UARTn Receiver Buffer Register
#define 	rU3THR      (*(volatile unsigned long *)  0x4009C000) //-- UARTn Transmit Holding Register
#define 	rU3DLL      (*(volatile unsigned long *)  0x4009C000) //-- UARTn Divisor Latch LSB register
#define 	rU3DLM      (*(volatile unsigned long *)  0x4009C004) //-- Latch MSB register
#define 	rU3IER      (*(volatile unsigned long *)  0x4009C004) //-- UARTn Interrupt Enable Register
#define 	rU3IIR      (*(volatile unsigned long *)  0x4009C008) //-- UARTn Interrupt Identification Register
#define 	rU3FCR      (*(volatile unsigned long *)  0x4009C008) //-- UARTn FIFO Control Register
#define 	rU3LCR      (*(volatile unsigned long *)  0x4009C00C) //-- UARTn Line Control Register
#define 	rU3LSR      (*(volatile unsigned long *)  0x4009C014) //-- UARTn Line Status Register
#define 	rU3SCR      (*(volatile unsigned long *)  0x4009C01C) //-- UARTn Scratch Pad Register
#define 	rU3ACR      (*(volatile unsigned long *)  0x4009C020) //-- UARTn Auto-baud Control Register
#define 	rU3ICR      (*(volatile unsigned long *)  0x4009C024) //-- UARTn IrDA Control Register
#define 	rU3FDR      (*(volatile unsigned long *)  0x4009C028) //-- UARTn Fractional Divider Register
#define 	rU3TER      (*(volatile unsigned long *)  0x4009C030) //-- UARTn Transmit Enable Register
#define 	rU3FIFOLVL  (*(volatile unsigned long *)  0x4009C058) //-- UARTn FIFO Level register

//----  UART1

#define 	rU1RBR  (*(volatile unsigned long *)  0x40010000) //-- UART1 Receiver Buffer Register
#define 	rU1THR  (*(volatile unsigned long *)  0x40010000) //-- UART1 Transmitter Holding Register
#define 	rU1DLL  (*(volatile unsigned long *)  0x40010000) //-- UART1 Divisor Latch LSB and MSB Registers
#define 	rU1DLM  (*(volatile unsigned long *)  0x40010004)
#define 	rU1IER  (*(volatile unsigned long *)  0x40010004) //-- UART1 Interrupt Enable Register
#define 	rU1IIR  (*(volatile unsigned long *)  0x40010008) //-- UART1 Interrupt Identification Register
#define 	rU1FCR  (*(volatile unsigned long *)  0x40010008) //-- UART1 FIFO Control Register
#define 	rU1LCR  (*(volatile unsigned long *)  0x4001000C) //-- UART1 Line Control Register
#define 	rU1MCR  (*(volatile unsigned long *)  0x40010010) //-- UART1 Modem Control Register
#define 	rU1LSR  (*(volatile unsigned long *)  0x40010014) //-- UART1 Line Status Register
#define 	rU1MSR  (*(volatile unsigned long *)  0x40010018) //-- UART1 Modem Status Register
#define 	rU1SCR  (*(volatile unsigned long *)  0x4001001C) //-- UART1 Scratch Pad Register
#define 	rU1ACR  (*(volatile unsigned long *)  0x40010020) //-- UART1 Auto-baud Control Register
#define 	rU1FDR  (*(volatile unsigned long *)  0x40010028) //-- UART1 Fractional Divider Register
#define 	rU1TER  (*(volatile unsigned long *)  0x40010030) //-- UART1 Transmit Enable Register
#define 	rU1RS485CTRL (*(volatile unsigned long *)  0x4001004C) //-- UART1 RS485 Control register
#define 	rU1ADRMATCH  (*(volatile unsigned long *)  0x40010050) //-- UART1 RS-485 Address Match register
#define 	rU1RS485ADRMATCH  rU1ADRMATCH
#define 	rU1RS485DLY  (*(volatile unsigned long *)  0x40010054) //-- UART1 RS-485 Delay value register
#define 	rU1FIFOLVL   (*(volatile unsigned long *)  0x40010058) //-- UART1 FIFO Level register

//---- CAN

#define 	rAFMR         (*(volatile unsigned long *)  0x4003C000) //-- Acceptance Filter Mode Register
#define 	rSFF_sa       (*(volatile unsigned long *)  0x4003C004) //-- Standard Frame Individual Start Address register
#define 	rSFF_GRP_sa   (*(volatile unsigned long *)  0x4003C008) //-- Standard Frame Group Start Address register
#define 	rEFF_sa       (*(volatile unsigned long *)  0x4003C00C) //-- Extended Frame Start Address register
#define 	rEFF_GRP_sa   (*(volatile unsigned long *)  0x4003C010) //-- Extended Frame Group Start Address register
#define 	rENDofTable   (*(volatile unsigned long *)  0x4003C014) //-- End of AF Tables register
#define 	rLUTerrAd     (*(volatile unsigned long *)  0x4003C018) //-- LUT Error Address register
#define 	rLUTerr       (*(volatile unsigned long *)  0x4003C01C) //-- LUT Error register
#define 	rFCANIE       (*(volatile unsigned long *)  0x4003C020) //-- Global FullCANInterrupt Enable register
#define 	rFCANIC0      (*(volatile unsigned long *)  0x4003C024) //-- FullCAN Interrupt and Capture registers
#define 	rFCANIC1      (*(volatile unsigned long *)  0x4003C028)
#define 	rCANTxSR      (*(volatile unsigned long *)  0x40040000) //-- Central Transmit Status Register
#define 	rCANRxSR      (*(volatile unsigned long *)  0x40040004) //-- Central Receive Status Register
#define 	rCANMSR       (*(volatile unsigned long *)  0x40040008) //-- Central Miscellaneous Status Register

#define 	rCAN1MOD    (*(volatile unsigned long *)  0x40044000) //-- CAN Mode register
#define 	rCAN1CMR    (*(volatile unsigned long *)  0x40044004) //-- CAN Command Register
#define 	rCAN1GSR    (*(volatile unsigned long *)  0x40044008) //-- CAN Global Status Register
#define 	rCAN1ICR    (*(volatile unsigned long *)  0x4004400C) //-- CAN Interrupt and Capture Register
#define 	rCAN1IER    (*(volatile unsigned long *)  0x40044010) //-- CAN Interrupt Enable Register
#define 	rCAN1BTR    (*(volatile unsigned long *)  0x40044014) //-- CAN Bus Timing Register
#define 	rCAN1EWL    (*(volatile unsigned long *)  0x40044018) //-- CAN Error Warning Limit register
#define 	rCAN1SR     (*(volatile unsigned long *)  0x4004401C) //-- CAN Status Register
#define 	rCAN1RFS    (*(volatile unsigned long *)  0x40044020) //-- CAN Receive Frame Status register
#define 	rCAN1RID    (*(volatile unsigned long *)  0x40044024) //-- CAN Receive Identifier register
#define 	rCAN1RDA    (*(volatile unsigned long *)  0x40044028) //-- CAN Receive Data register A
#define 	rCAN1RDB    (*(volatile unsigned long *)  0x4004402C) //-- CAN Receive Data register B
#define 	rCAN1TFI1   (*(volatile unsigned long *)  0x40044030) //-- CAN Transmit Frame Information register
#define 	rCAN1TID1   (*(volatile unsigned long *)  0x40044034) //-- CAN Transmit Identifier register
#define 	rCAN1TDA1   (*(volatile unsigned long *)  0x40044038) //-- CAN Transmit Data register A
#define 	rCAN1TDB1   (*(volatile unsigned long *)  0x4004403C) //-- CAN Transmit Data register B
#define 	rCAN1TFI2   (*(volatile unsigned long *)  0x40044040)
#define 	rCAN1TID2   (*(volatile unsigned long *)  0x40044044)
#define 	rCAN1TDA2   (*(volatile unsigned long *)  0x40044048)
#define 	rCAN1TDB2   (*(volatile unsigned long *)  0x4004404C)
#define 	rCAN1TFI3   (*(volatile unsigned long *)  0x40044050)
#define 	rCAN1TID3   (*(volatile unsigned long *)  0x40044054)
#define 	rCAN1TDA3   (*(volatile unsigned long *)  0x40044058)
#define 	rCAN1TDB3   (*(volatile unsigned long *)  0x4004405C)

#define 	rCAN2MOD    (*(volatile unsigned long *)  0x40048000) //-- CAN Mode register
#define 	rCAN2CMR    (*(volatile unsigned long *)  0x40048004) //-- CAN Command Register
#define 	rCAN2GSR    (*(volatile unsigned long *)  0x40048008) //-- CAN Global Status Register
#define 	rCAN2ICR    (*(volatile unsigned long *)  0x4004800C) //-- CAN Interrupt and Capture Register
#define 	rCAN2IER    (*(volatile unsigned long *)  0x40048010) //-- CAN Interrupt Enable Register
#define 	rCAN2BTR    (*(volatile unsigned long *)  0x40048014) //-- CAN Bus Timing Register
#define 	rCAN2EWL    (*(volatile unsigned long *)  0x40048018) //-- CAN Error Warning Limit register
#define 	rCAN2SR     (*(volatile unsigned long *)  0x4004801C) //-- CAN Status Register
#define 	rCAN2RFS    (*(volatile unsigned long *)  0x40048020) //-- CAN Receive Frame Status register
#define 	rCAN2RID    (*(volatile unsigned long *)  0x40048024) //-- CAN Receive Identifier register
#define 	rCAN2RDA    (*(volatile unsigned long *)  0x40048028) //-- CAN Receive Data register A
#define 	rCAN2RDB    (*(volatile unsigned long *)  0x4004802C) //-- CAN Receive Data register B
#define 	rCAN2TFI1   (*(volatile unsigned long *)  0x40048030) //-- CAN Transmit Frame Information register
#define 	rCAN2TID1   (*(volatile unsigned long *)  0x40048034) //-- CAN Transmit Identifier register
#define 	rCAN2TDA1   (*(volatile unsigned long *)  0x40048038) //-- CAN Transmit Data register A
#define 	rCAN2TDB1   (*(volatile unsigned long *)  0x4004803C) //-- CAN Transmit Data register B
#define 	rCAN2TFI2   (*(volatile unsigned long *)  0x40048040)
#define 	rCAN2TID2   (*(volatile unsigned long *)  0x40048044)
#define 	rCAN2TDA2   (*(volatile unsigned long *)  0x40048048)
#define 	rCAN2TDB2   (*(volatile unsigned long *)  0x4004804C)
#define 	rCAN2TFI3   (*(volatile unsigned long *)  0x40048050)
#define 	rCAN2TID3   (*(volatile unsigned long *)  0x40048054)
#define 	rCAN2TDA3   (*(volatile unsigned long *)  0x40048058)
#define 	rCAN2TDB3   (*(volatile unsigned long *)  0x4004805C)

#define 	rCANSLEEPCLR    (*(volatile unsigned long *)  0x400FC110) //-- CAN Sleep Clear register
#define 	rCANWAKEFLAGS   (*(volatile unsigned long *)  0x400FC114) //-- CAN Wake-up Flags register

//---- SPI

#define 	rS0SPCR   (*(volatile unsigned long *)  0x40020000) //-- SPI Control Register
#define 	rS0SPSR   (*(volatile unsigned long *)  0x40020004) //-- SPI Status Register
#define 	rS0SPDR   (*(volatile unsigned long *)  0x40020008) //-- SPI Data Register
#define 	rS0SPCCR  (*(volatile unsigned long *)  0x4002000C) //-- SPI Clock Counter Register
//#define 	SPTCR    (*(volatile unsigned long *)  0x40020010) //-- SPI Test Control Register
//#define 	SPTSR    (*(volatile unsigned long *)  0x40020014) //-- SPI Test Status Register
#define 	S0SPINT  (*(volatile unsigned long *)  0x4002001C) //-- SPI Interrupt Register

//---- SSP

#define 	rSSP0CR0    (*(volatile unsigned long *)  0x40088000) //-- SSP0 Control Register 0
#define 	rSSP0CR1    (*(volatile unsigned long *)  0x40088004) //-- SSP0 Control Register 1
#define 	rSSP0DR     (*(volatile unsigned long *)  0x40088008) //-- SSP0 Data Register
#define 	rSSP0SR     (*(volatile unsigned long *)  0x4008800C) //-- SSP0 Status Register
#define 	rSSP0CPSR   (*(volatile unsigned long *)  0x40088010) //-- SSP0 Clock Prescale Register
#define 	rSSP0IMSC   (*(volatile unsigned long *)  0x40088014) //-- SSP0 Interrupt Mask Set/Clear Register
#define 	rSSP0RIS    (*(volatile unsigned long *)  0x40088018) //-- SSP0 Raw Interrupt Status Register
#define 	rSSP0MIS    (*(volatile unsigned long *)  0x4008801C) //-- SSP0 Masked Interrupt Status Register
#define 	rSSP0ICR    (*(volatile unsigned long *)  0x40088020) //-- SSP0 Interrupt Clear Register
#define 	rSSP0DMACR  (*(volatile unsigned long *)  0x40088024) //-- SSP0 DMA Control Register


#define 	rSSP1CR0    (*(volatile unsigned long *)  0x40030000) //-- SSP1 Control Register 0
#define 	rSSP1CR1    (*(volatile unsigned long *)  0x40030004) //-- SSP1 Control Register 1
#define 	rSSP1DR     (*(volatile unsigned long *)  0x40030008) //-- SSP1 Data Register
#define 	rSSP1SR     (*(volatile unsigned long *)  0x4003000C) //-- SSP1 Status Register
#define 	rSSP1CPSR   (*(volatile unsigned long *)  0x40030010) //-- SSP1 Clock Prescale Register
#define 	rSSP1IMSC   (*(volatile unsigned long *)  0x40030014) //-- SSP1 Interrupt Mask Set/Clear Register
#define 	rSSP1RIS    (*(volatile unsigned long *)  0x40030018) //-- SSP1 Raw Interrupt Status Register
#define 	rSSP1MIS    (*(volatile unsigned long *)  0x4003001C) //-- SSP1 Masked Interrupt Status Register
#define 	rSSP1ICR    (*(volatile unsigned long *)  0x40030020) //-- SSP1 Interrupt Clear Register
#define 	rSSP1DMACR  (*(volatile unsigned long *)  0x40030024) //-- SSP1 DMA Control Register

//---- I2C

#define 	rI2C0CONSET      (*(volatile unsigned long *)  0x4001C000) //-- I2C Control Set register
#define 	rI2C0STAT        (*(volatile unsigned long *)  0x4001C004) //-- I2C Status register
#define 	rI2C0DAT         (*(volatile unsigned long *)  0x4001C008) //-- I2C Data register
#define 	rI2C0ADR0        (*(volatile unsigned long *)  0x4001C00C) //-- I2C Slave Address registers
#define 	rI2C0SCLH        (*(volatile unsigned long *)  0x4001C010) //-- I2C SCL HIGH duty cycle register
#define 	rI2C0SCLL        (*(volatile unsigned long *)  0x4001C014) //-- I2C SCL Low duty cycle register
#define 	rI2C0CONCLR      (*(volatile unsigned long *)  0x4001C018) //-- I2C Control Clear register
#define 	rI2C0MMCTRL      (*(volatile unsigned long *)  0x4001C01C) //-- I2C Monitor mode control register
#define 	rI2C0ADR1        (*(volatile unsigned long *)  0x4001C020)
#define 	rI2C0ADR2        (*(volatile unsigned long *)  0x4001C024)
#define 	rI2C0ADR3        (*(volatile unsigned long *)  0x4001C028)
#define 	rI2C0DATA_BUFFER (*(volatile unsigned long *)  0x4001C02C) //-- I2C Data buffer register
#define 	rI2C0MASK0       (*(volatile unsigned long *)  0x4001C030) //-- I2C Mask registers
#define 	rI2C0MASK1       (*(volatile unsigned long *)  0x4001C034)
#define 	rI2C0MASK2       (*(volatile unsigned long *)  0x4001C038)
#define 	rI2C0MASK3       (*(volatile unsigned long *)  0x4001C03C)

#define 	rI2C1CONSET       (*(volatile unsigned long *)  0x4005C000) //-- I2C Control Set register
#define 	rI2C1STAT         (*(volatile unsigned long *)  0x4005C004) //-- I2C Status register
#define 	rI2C1DAT          (*(volatile unsigned long *)  0x4005C008) //-- I2C Data register
#define 	rI2C1ADR0         (*(volatile unsigned long *)  0x4005C00C) //-- I2C Slave Address registers
#define 	rI2C1SCLH         (*(volatile unsigned long *)  0x4005C010) //-- I2C SCL HIGH duty cycle register
#define 	rI2C1SCLL         (*(volatile unsigned long *)  0x4005C014) //-- I2C SCL Low duty cycle register
#define 	rI2C1CONCLR       (*(volatile unsigned long *)  0x4005C018) //-- I2C Control Clear register
#define 	rI2C1MMCTRL       (*(volatile unsigned long *)  0x4005C01C) //-- I2C Monitor mode control register
#define 	rI2C1ADR1         (*(volatile unsigned long *)  0x4005C020)
#define 	rI2C1ADR2         (*(volatile unsigned long *)  0x4005C024)
#define 	rI2C1ADR3         (*(volatile unsigned long *)  0x4005C028)
#define 	rI2C1DATA_BUFFER  (*(volatile unsigned long *)  0x4005C02C) //-- I2C Data buffer register
#define 	rI2C1MASK0        (*(volatile unsigned long *)  0x4005C030) //-- I2C Mask registers
#define 	rI2C1MASK1        (*(volatile unsigned long *)  0x4005C034)
#define 	rI2C1MASK2        (*(volatile unsigned long *)  0x4005C038)
#define 	rI2C1MASK3        (*(volatile unsigned long *)  0x4005C03C)

#define 	rI2C2CONSET       (*(volatile unsigned long *)  0x400A0000) //-- I2C Control Set register
#define 	rI2C2STAT         (*(volatile unsigned long *)  0x400A0004) //-- I2C Status register
#define 	rI2C2DAT          (*(volatile unsigned long *)  0x400A0008) //-- I2C Data register
#define 	rI2C2ADR0         (*(volatile unsigned long *)  0x400A000C) //-- I2C Slave Address registers
#define 	rI2C2SCLH         (*(volatile unsigned long *)  0x400A0010) //-- I2C SCL HIGH duty cycle register
#define 	rI2C2SCLL         (*(volatile unsigned long *)  0x400A0014) //-- I2C SCL Low duty cycle register
#define 	rI2C2CONCLR       (*(volatile unsigned long *)  0x400A0018) //-- I2C Control Clear register
#define 	rI2C2MMCTRL       (*(volatile unsigned long *)  0x400A001C) //-- I2C Monitor mode control register
#define 	rI2C2ADR1         (*(volatile unsigned long *)  0x400A0020)
#define 	rI2C2ADR2         (*(volatile unsigned long *)  0x400A0024)
#define 	rI2C2ADR3         (*(volatile unsigned long *)  0x400A0028)
#define 	rI2C2DATA_BUFFER  (*(volatile unsigned long *)  0x400A002C) //-- I2C Data buffer register
#define 	rI2C2MASK0        (*(volatile unsigned long *)  0x400A0030) //-- I2C Mask registers
#define 	rI2C2MASK1        (*(volatile unsigned long *)  0x400A0034)
#define 	rI2C2MASK2        (*(volatile unsigned long *)  0x400A0038)
#define 	rI2C2MASK3        (*(volatile unsigned long *)  0x400A003C)

//---- I2S

#define 	rI2SDAO        (*(volatile unsigned long *)  0x400A8000) //-- Digital Audio Output register
#define 	rI2SDAI        (*(volatile unsigned long *)  0x400A8004) //-- Digital Audio Input register
#define 	rI2STXFIFO     (*(volatile unsigned long *)  0x400A8008) //-- Transmit FIFO register
#define 	rI2SRXFIFO     (*(volatile unsigned long *)  0x400A800C) //-- Receive FIFO register
#define 	rI2SSTATE      (*(volatile unsigned long *)  0x400A8010) //-- Status Feedback register
#define 	rI2SDMA1       (*(volatile unsigned long *)  0x400A8014) //-- DMA Configuration Register 1
#define 	rI2SDMA2       (*(volatile unsigned long *)  0x400A8018) //-- DMA Configuration Register 2
#define 	rI2SIRQ        (*(volatile unsigned long *)  0x400A801C) //-- Interrupt Request Control register
#define 	rI2STXRATE     (*(volatile unsigned long *)  0x400A8020) //-- Transmit Clock Rate register
#define 	rI2SRXRATE     (*(volatile unsigned long *)  0x400A8024) //-- Receive Clock Rate register
#define 	rI2STXBITRATE  (*(volatile unsigned long *)  0x400A8028) //-- Transmit Clock Bit Rate register
#define 	rI2SRXBITRATE  (*(volatile unsigned long *)  0x400A802C) //-- Receive Clock Bit Rate register
#define 	rI2STXMODE     (*(volatile unsigned long *)  0x400A8030) //-- Transmit Mode Control register
#define 	rI2SRXMODE     (*(volatile unsigned long *)  0x400A8034) //-- Receive Mode Control register

//---- Timers

#define 	rT0IR    (*(volatile unsigned long *)  0x40004000) //-- Interrupt Register
#define 	rT0TCR   (*(volatile unsigned long *)  0x40004004) //-- Timer Control Register
#define 	rT0TC    (*(volatile unsigned long *)  0x40004008) //-- Timer Counter registers
#define 	rT0PR    (*(volatile unsigned long *)  0x4000400C) //-- Prescale register
#define 	rT0PC    (*(volatile unsigned long *)  0x40004010) //-- Prescale Counter register
#define 	rT0MCR   (*(volatile unsigned long *)  0x40004014) //-- Match Control Register
#define 	rT0MR0   (*(volatile unsigned long *)  0x40004018) //-- Match Register 0
#define 	rT0MR1   (*(volatile unsigned long *)  0x4000401C) //-- Match Register 1
#define 	rT0MR2   (*(volatile unsigned long *)  0x40004020) //-- Match Register 2
#define 	rT0MR3   (*(volatile unsigned long *)  0x40004024) //-- Match Register 3
#define 	rT0CCR   (*(volatile unsigned long *)  0x40004028) //-- Capture Control Register
#define 	rT0CR0   (*(volatile unsigned long *)  0x4000402C) //-- Capture Register 0
#define 	rT0CR1   (*(volatile unsigned long *)  0x40004030) //-- Capture Register 1
#define 	rT0EMR   (*(volatile unsigned long *)  0x4000403C) //-- External Match Register
#define 	rT0CTCR  (*(volatile unsigned long *)  0x40004070) //-- Count Control Register

#define 	rT1IR    (*(volatile unsigned long *)  0x40008000) //-- Interrupt Register
#define 	rT1TCR   (*(volatile unsigned long *)  0x40008004) //-- Timer Control Register
#define 	rT1TC    (*(volatile unsigned long *)  0x40008008) //-- Timer Counter registers
#define 	rT1PR    (*(volatile unsigned long *)  0x4000800C) //-- Prescale register
#define 	rT1PC    (*(volatile unsigned long *)  0x40008010) //-- Prescale Counter register
#define 	rT1MCR   (*(volatile unsigned long *)  0x40008014) //-- Match Control Register
#define 	rT1MR0   (*(volatile unsigned long *)  0x40008018) //-- Match Register 0
#define 	rT1MR1   (*(volatile unsigned long *)  0x4000801C) //-- Match Register 1
#define 	rT1MR2   (*(volatile unsigned long *)  0x40008020) //-- Match Register 2
#define 	rT1MR3   (*(volatile unsigned long *)  0x40008024) //-- Match Register 3
#define 	rT1CCR   (*(volatile unsigned long *)  0x40008028) //-- Capture Control Register
#define 	rT1CR0   (*(volatile unsigned long *)  0x4000802C) //-- Capture Register 0
#define 	rT1CR1   (*(volatile unsigned long *)  0x40008030) //-- Capture Register 1
#define 	rT1EMR   (*(volatile unsigned long *)  0x4000803C) //-- External Match Register
#define 	rT1CTCR  (*(volatile unsigned long *)  0x40008070) //-- Count Control Register

#define 	rT2IR    (*(volatile unsigned long *)  0x40090000) //-- Interrupt Register
#define 	rT2TCR   (*(volatile unsigned long *)  0x40090004) //-- Timer Control Register
#define 	rT2TC    (*(volatile unsigned long *)  0x40090008) //-- Timer Counter registers
#define 	rT2PR    (*(volatile unsigned long *)  0x4009000C) //-- Prescale register
#define 	rT2PC    (*(volatile unsigned long *)  0x40090010) //-- Prescale Counter register
#define 	rT2MCR   (*(volatile unsigned long *)  0x40090014) //-- Match Control Register
#define 	rT2MR0   (*(volatile unsigned long *)  0x40090018) //-- Match Register 0
#define 	rT2MR1   (*(volatile unsigned long *)  0x4009001C) //-- Match Register 1
#define 	rT2MR2   (*(volatile unsigned long *)  0x40090020) //-- Match Register 2
#define 	rT2MR3   (*(volatile unsigned long *)  0x40090024) //-- Match Register 3
#define 	rT2CCR   (*(volatile unsigned long *)  0x40090028) //-- Capture Control Register
#define 	rT2CR0   (*(volatile unsigned long *)  0x4009002C) //-- Capture Register 0
#define 	rT2CR1   (*(volatile unsigned long *)  0x40090030) //-- Capture Register 1
#define 	rT2EMR   (*(volatile unsigned long *)  0x4009003C) //-- External Match Register
#define 	rT2CTCR  (*(volatile unsigned long *)  0x40090070) //-- Count Control Register

#define 	rT3IR    (*(volatile unsigned long *)  0x40094000) //-- Interrupt Register
#define 	rT3TCR   (*(volatile unsigned long *)  0x40094004) //-- Timer Control Register
#define 	rT3TC    (*(volatile unsigned long *)  0x40094008) //-- Timer Counter registers
#define 	rT3PR    (*(volatile unsigned long *)  0x4009400C) //-- Prescale register
#define 	rT3PC    (*(volatile unsigned long *)  0x40094010) //-- Prescale Counter register
#define 	rT3MCR   (*(volatile unsigned long *)  0x40094014) //-- Match Control Register
#define 	rT3MR0   (*(volatile unsigned long *)  0x40094018) //-- Match Register 0
#define 	rT3MR1   (*(volatile unsigned long *)  0x4009401C) //-- Match Register 0
#define 	rT3MR2   (*(volatile unsigned long *)  0x40094020) //-- Match Register 0
#define 	rT3MR3   (*(volatile unsigned long *)  0x40094024) //-- Match Register 0
#define 	rT3CCR   (*(volatile unsigned long *)  0x40094028) //-- Capture Control Register
#define 	rT3CR0   (*(volatile unsigned long *)  0x4009402C) //-- Capture Register 0
#define 	rT3CR1   (*(volatile unsigned long *)  0x40094030) //-- Capture Register 1
#define 	rT3EMR   (*(volatile unsigned long *)  0x4009403C) //-- External Match Register
#define 	rT3CTCR  (*(volatile unsigned long *)  0x40094070) //-- Count Control Register

//---- Sys int timer

#define 	rRICOMPVAL  (*(volatile unsigned long *)  0x400B0000) //-- RI Compare Value register
#define 	rRIMASK     (*(volatile unsigned long *)  0x400B0004) //-- RI Mask register
#define 	rRICTRL     (*(volatile unsigned long *)  0x400B0008) //-- RI Control register
#define 	rRICOUNTER  (*(volatile unsigned long *)  0x400B000C) //-- RI 32-bit counter

//---- Sys tick timer

#define 	rSTCTRL    (*(volatile unsigned long *)  0xE000E010) //-- System Timer Control and status register
#define 	rSTRELOAD  (*(volatile unsigned long *)  0xE000E014) //-- System Timer Reload value register
#define 	rSTCURR    (*(volatile unsigned long *)  0xE000E018) //-- System Timer Current value register
#define 	rSTCALIB   (*(volatile unsigned long *)  0xE000E01C) //-- System Timer Calibration value register

//---- PWM

#define 	rPWM1IR    (*(volatile unsigned long *)  0x40018000) //-- PWM Interrupt Register
#define 	rPWM1TCR   (*(volatile unsigned long *)  0x40018004) //-- PWM Timer Control Register
#define 	rPWM1TC    (*(volatile unsigned long *)  0x40018008)
#define 	rPWM1PR    (*(volatile unsigned long *)  0x4001800C)
#define 	rPWM1PC    (*(volatile unsigned long *)  0x40018010)
#define 	rPWM1MCR   (*(volatile unsigned long *)  0x40018014) //-- PWM Match Control Register
#define 	rPWM1MR0   (*(volatile unsigned long *)  0x40018018)
#define 	rPWM1MR1   (*(volatile unsigned long *)  0x4001801C)
#define 	rPWM1MR2   (*(volatile unsigned long *)  0x40018020)
#define 	rPWM1MR3   (*(volatile unsigned long *)  0x40018024)
#define 	rPWM1CCR   (*(volatile unsigned long *)  0x40018028) //-- PWM Capture Control Register
#define 	rPWM1CR0   (*(volatile unsigned long *)  0x4001802C)
#define 	rPWM1CR1   (*(volatile unsigned long *)  0x40018030)
#define 	rPWM1CR2   (*(volatile unsigned long *)  0x40018034)
#define 	rPWM1CR3   (*(volatile unsigned long *)  0x40018038)
#define 	rPWM1MR4   (*(volatile unsigned long *)  0x40018040)
#define 	rPWM1MR5   (*(volatile unsigned long *)  0x40018044)
#define 	rPWM1MR6   (*(volatile unsigned long *)  0x40018048)
#define 	rPWM1PCR   (*(volatile unsigned long *)  0x4001804C) //-- PWM Control Register
#define 	rPWM1LER   (*(volatile unsigned long *)  0x40018050) //-- PWM Latch Enable Register
#define 	rPWM1CTCR  (*(volatile unsigned long *)  0x40018070) //-- PWM Count Control Register

//---- Motor control PWM

#define 	rMCCON         (*(volatile unsigned long *)  0x400B8000) //-- MCPWM Control read address
#define 	rMCCON_SET     (*(volatile unsigned long *)  0x400B8004) //-- MCPWM Control set address
#define 	rMCCON_CLR     (*(volatile unsigned long *)  0x400B8008) //-- MCPWM Control clear address
#define 	rMCCAPCON      (*(volatile unsigned long *)  0x400B800C) //-- MCPWM Capture Control read address
#define 	rMCCAPCON_SET  (*(volatile unsigned long *)  0x400B8010) //-- MCPWM Capture Control set address
#define 	rMCCAPCON_CLR  (*(volatile unsigned long *)  0x400B8014) //-- MCPWM Capture control clear address
#define 	rMCTC0         (*(volatile unsigned long *)  0x400B8018) //-- MCPWM Timer/Counter 0-2 registers
#define 	rMCTC1         (*(volatile unsigned long *)  0x400B801C)
#define 	rMCTC2         (*(volatile unsigned long *)  0x400B8020)
#define 	rMCLIM0        (*(volatile unsigned long *)  0x400B8024) //-- MCPWM Limit 0-2 registers
#define 	rMCLIM1        (*(volatile unsigned long *)  0x400B8028)
#define 	rMCLIM2        (*(volatile unsigned long *)  0x400B802C)
#define 	rMCMAT0        (*(volatile unsigned long *)  0x400B8030) //-- MCPWM Match 0-2 registers
#define 	rMCMAT1        (*(volatile unsigned long *)  0x400B8034)
#define 	rMCMAT2        (*(volatile unsigned long *)  0x400B8038)
#define 	rMCDT          (*(volatile unsigned long *)  0x400B803C) //-- MCPWM Dead-time register
#define 	rMCCP          (*(volatile unsigned long *)  0x400B8040) //-- MCPWM Communication Pattern register
#define 	rMCCAP0        (*(volatile unsigned long *)  0x400B8044) //-- MCPWM Capture read addresses
#define 	rMCCAP1        (*(volatile unsigned long *)  0x400B8048)
#define 	rMCCAP2        (*(volatile unsigned long *)  0x400B804C)
#define 	rMCINTEN       (*(volatile unsigned long *)  0x400B8050) //-- MCPWM Interrupt Enable read address
#define 	rMCINTEN_SET   (*(volatile unsigned long *)  0x400B8054) //-- MCPWM Interrupt Enable set address
#define 	rMCINTEN_CLR   (*(volatile unsigned long *)  0x400B8058) //-- MCPWM Interrupt Enable clear address
#define 	rMCCNTCON      (*(volatile unsigned long *)  0x400B805C) //-- MCPWM Count Control read address
#define 	rMCCNTCON_SET  (*(volatile unsigned long *)  0x400B8060) //-- MCPWM Count Control set address
#define 	rMCCNTCON_CLR  (*(volatile unsigned long *)  0x400B8064) //-- MCPWM Count Control clear address
#define 	rMCINTF        (*(volatile unsigned long *)  0x400B8068) //-- MCPWM Interrupt Flags read address
#define 	rMCINTF_SET    (*(volatile unsigned long *)  0x400B806C) //-- MCPWM Interrupt Flags set address
#define 	rMCINTF_CLR    (*(volatile unsigned long *)  0x400B8070) //-- MCPWM Interrupt Flags clear address
#define 	rMCCAP_CLR     (*(volatile unsigned long *)  0x400B8074) //--    MCPWM Capture clear address

//---- Quadrature Encoder Interface

#define 	rQEICON     (*(volatile unsigned long *)  0x400BC000) //-- QEI Control register
#define 	rQEICONF    (*(volatile unsigned long *)  0x400BC008) //-- QEI Configuration register
#define 	rQEISTAT    (*(volatile unsigned long *)  0x400BC004) //-- QEI Status register
#define 	rQEIPOS     (*(volatile unsigned long *)  0x400BC00C) //-- QEI Position register
#define 	rQEIMAXPOS  (*(volatile unsigned long *)  0x400BC010) //-- QEI Maximum Position register
#define 	rCMPOS0     (*(volatile unsigned long *)  0x400BC014) //-- QEI Position Compare register 0
#define 	rCMPOS1     (*(volatile unsigned long *)  0x400BC018) //-- QEI Position Compare register 1
#define 	rCMPOS2     (*(volatile unsigned long *)  0x400BC01C) //-- QEI Position Compare register 2
#define 	rINXCNT     (*(volatile unsigned long *)  0x400BC020) //-- QEI Index Count register
#define 	rINXCMP     (*(volatile unsigned long *)  0x400BC024) //-- QEI Index Compare register
#define 	rQEILOAD    (*(volatile unsigned long *)  0x400BC028) //-- QEI Timer Reload register
#define 	rQEITIME    (*(volatile unsigned long *)  0x400BC02C) //-- QEI Timer register
#define 	rQEIVEL     (*(volatile unsigned long *)  0x400BC030) //-- QEI Velocity register
#define 	rQEICAP     (*(volatile unsigned long *)  0x400BC034) //-- QEI Velocity Capture register
#define 	rVELCOMP    (*(volatile unsigned long *)  0x400BC038) //-- QEI Velocity Compare register
#define 	rFILTER     (*(volatile unsigned long *)  0x400BC03C) //-- QEI Digital Filter register

#define 	rQEIINSTAT  (*(volatile unsigned long *)  0x400BCFE0) //-- QEI Interrupt status register
#define 	rQEISET     (*(volatile unsigned long *)  0x400BCFEC) //-- QEI Interrupt Set register
#define 	rQEICLR     (*(volatile unsigned long *)  0x400BCFE8) //-- QEI Interrupt Clear register
#define 	rQEIIE      (*(volatile unsigned long *)  0x400BCFE4) //-- QEI Interrupt Enable register
#define 	rQEIIES     (*(volatile unsigned long *)  0x400BCFDC) //-- QEI Interrupt Enable Set register
#define 	rQEIIEC     (*(volatile unsigned long *)  0x400BCFD8) //-- QEI Interrupt Enable Clear register

//---- RTC

#define 	rILR          (*(volatile unsigned long *)  0x40024000) //-- Interrupt Location Register
#define 	rCCR          (*(volatile unsigned long *)  0x40024008) //-- Clock Control Register
#define 	rCIIR         (*(volatile unsigned long *)  0x4002400C) //-- Counter Increment Interrupt Register
#define 	rAMR          (*(volatile unsigned long *)  0x40024010) //-- Alarm Mask Register
#define 	rRTC_AUX      (*(volatile unsigned long *)  0x4002405C) //-- RTC Auxiliary control register
#define 	rRTC_AUXEN    (*(volatile unsigned long *)  0x40024058) //-- RTC Auxiliary Enable register
#define 	rCTIME0       (*(volatile unsigned long *)  0x40024014) //-- Consolidated Time Register 0
#define 	rCTIME1       (*(volatile unsigned long *)  0x40024018) //-- Consolidated Time Register 1
#define 	rCTIME2       (*(volatile unsigned long *)  0x4002401C) //-- Consolidated Time Register 2
#define 	rSEC          (*(volatile unsigned long *)  0x40024020)
#define 	rMIN          (*(volatile unsigned long *)  0x40024024)
#define 	rHOUR         (*(volatile unsigned long *)  0x40024028)
#define 	rDOM          (*(volatile unsigned long *)  0x4002402C)
#define 	rDOW          (*(volatile unsigned long *)  0x40024030)
#define 	rDOY          (*(volatile unsigned long *)  0x40024034)
#define 	rMONTH        (*(volatile unsigned long *)  0x40024038)
#define 	rYEAR         (*(volatile unsigned long *)  0x4002403C)
#define 	rCALIBRATION  (*(volatile unsigned long *)  0x40024040) //-- Calibration register
#define 	rGPREG0       (*(volatile unsigned long *)  0x40024044) //-- General purpose registers 0 to 4
#define 	rGPREG1       (*(volatile unsigned long *)  0x40024048)
#define 	rGPREG2       (*(volatile unsigned long *)  0x4002404C)
#define 	rGPREG3       (*(volatile unsigned long *)  0x40024050)
#define 	rGPREG4       (*(volatile unsigned long *)  0x40024054)
#define 	rALSEC        (*(volatile unsigned long *)  0x40024060)
#define 	rALMIN        (*(volatile unsigned long *)  0x40024064)
#define 	rALHOUR       (*(volatile unsigned long *)  0x40024068)
#define 	rALDOM        (*(volatile unsigned long *)  0x4002406C)
#define 	rALDOW        (*(volatile unsigned long *)  0x40024070)
#define 	rALDOY        (*(volatile unsigned long *)  0x40024074)
#define 	rALMON        (*(volatile unsigned long *)  0x40024078)
#define 	rALYEAR       (*(volatile unsigned long *)  0x4002407C)

//----  Watchdog

#define 	rWDMOD     (*(volatile unsigned long *)  0x40000000) //--  Watchdog Mode register
#define 	rWDTC      (*(volatile unsigned long *)  0x40000004) //--  Watchdog Timer Constant register
#define 	rWDFEED    (*(volatile unsigned long *)  0x40000008) //--  Watchdog Feed register
#define 	rWDTV      (*(volatile unsigned long *)  0x4000000C) //--  Watchdog Timer Value register
#define 	rWDCLKSEL  (*(volatile unsigned long *)  0x40000010) //--  Watchdog Timer Clock Source Selection register

//---- ADC

#define 	rAD0CR      (*(volatile unsigned long *)  0x40034000) //-- A/D Control Register
#define 	rAD0GDR     (*(volatile unsigned long *)  0x40034004) //-- A/D Global Data Register
#define 	rAD0INTEN   (*(volatile unsigned long *)  0x4003400C) //-- A/D Interrupt Enable register
#define 	rAD0DR0     (*(volatile unsigned long *)  0x40034010) //-- A/D Data Registers
#define 	rAD0DR1     (*(volatile unsigned long *)  0x40034014)
#define 	rAD0DR2     (*(volatile unsigned long *)  0x40034018)
#define 	rAD0DR3     (*(volatile unsigned long *)  0x4003401C)
#define 	rAD0DR4     (*(volatile unsigned long *)  0x40034020)
#define 	rAD0DR5     (*(volatile unsigned long *)  0x40034024)
#define 	rAD0DR6     (*(volatile unsigned long *)  0x40034028)
#define 	rAD0DR7     (*(volatile unsigned long *)  0x4003402C)
#define 	rAD0STAT    (*(volatile unsigned long *)  0x40034030) //-- A/D Status register
#define 	rADTRIM     (*(volatile unsigned long *)  0x40034034) //-- A/D Trim register

//---- DAC

#define 	rDACR       (*(volatile unsigned long *)  0x4008C000) //-- D/A Converter Register
#define 	rDACCTRL    (*(volatile unsigned long *)  0x4008C004) //-- D/A Converter Control register
#define 	rDACCNTVAL  (*(volatile unsigned long *)  0x4008C008) //-- D/A Converter Counter Value register

//---- DMA controler

#define 	rDMACIntStat        (*(volatile unsigned long *)  0x50004000) //-- DMA Interrupt Status register
#define 	rDMACIntTCStat      (*(volatile unsigned long *)  0x50004004) //-- DMA Interrupt Terminal Count Request Status register
#define 	rDMACIntTCClear     (*(volatile unsigned long *)  0x50004008) //-- DMA Interrupt Terminal Count Request Clear register
#define 	rDMACIntErrStat     (*(volatile unsigned long *)  0x5000400C) //-- DMA Interrupt Error Status register
#define 	rDMACIntErrClr      (*(volatile unsigned long *)  0x50004010) //-- DMA Interrupt Error Clear register
#define 	rDMACRawIntTCStat   (*(volatile unsigned long *)  0x50004014) //-- DMA Raw Interrupt Terminal Count Status register
#define 	rDMACRawIntErrStat  (*(volatile unsigned long *)  0x50004018) //-- DMA Raw Error Interrupt Status register
#define 	rDMACEnbldChns      (*(volatile unsigned long *)  0x5000401C) //-- DMA Enabled Channel register
#define 	rDMACSoftBReq       (*(volatile unsigned long *)  0x50004020) //-- DMA Software Burst Request register
#define 	rDMACSoftSReq       (*(volatile unsigned long *)  0x50004024) //-- DMA Software Single Request register
#define 	rDMACSoftLBReq      (*(volatile unsigned long *)  0x50004028) //-- DMA Software Last Burst Request register
#define 	rDMACSoftLSReq      (*(volatile unsigned long *)  0x5000402C) //-- DMA Software Last Single Request register
#define 	rDMACConfig         (*(volatile unsigned long *)  0x50004030) //-- DMA Configuration register
#define 	rDMACSync           (*(volatile unsigned long *)  0x50004034) //-- DMA Synchronization register
#define 	rDMAREQSEL          (*(volatile unsigned long *)  0x400FC1C4) //-- DMA Request Select register

#define 	rDMACC0SrcAddr      (*(volatile unsigned long *)  0x50004100) //-- DMA Channel Source Address registers
#define 	rDMACC0DestAddr     (*(volatile unsigned long *)  0x50004104) //-- DMA Channel Destination Address registers
#define 	rDMACC0LLI          (*(volatile unsigned long *)  0x50004108) //-- DMA Channel Linked List Item registers
#define 	rDMACC0Control      (*(volatile unsigned long *)  0x5000410C) //-- DMA channel control registers
#define 	rDMACC0Config       (*(volatile unsigned long *)  0x50004110) //-- DMA Channel Configuration registers

#define 	rDMACC1SrcAddr      (*(volatile unsigned long *)  0x50004120) //-- DMA Channel Source Address registers
#define 	rDMACC1DestAddr     (*(volatile unsigned long *)  0x50004124) //-- DMA Channel Destination Address registers
#define 	rDMACC1LLI          (*(volatile unsigned long *)  0x50004128) //-- DMA Channel Linked List Item registers
#define 	rDMACC1Control      (*(volatile unsigned long *)  0x5000412C) //-- DMA channel control registers
#define 	rDMACC1Config       (*(volatile unsigned long *)  0x50004130) //-- DMA Channel Configuration registers

#define 	rDMACC2SrcAddr      (*(volatile unsigned long *)  0x50004140) //-- DMA Channel Source Address registers
#define 	rDMACC2DestAddr     (*(volatile unsigned long *)  0x50004144) //-- DMA Channel Destination Address registers
#define 	rDMACC2LLI          (*(volatile unsigned long *)  0x50004148) //-- DMA Channel Linked List Item registers
#define 	rDMACC2Control      (*(volatile unsigned long *)  0x5000414C) //-- DMA channel control registers
#define 	rDMACC2Config       (*(volatile unsigned long *)  0x50004150) //-- DMA Channel Configuration registers

#define 	rDMACC3SrcAddr      (*(volatile unsigned long *)  0x50004160) //-- DMA Channel Source Address registers
#define 	rDMACC3DestAddr     (*(volatile unsigned long *)  0x50004164) //-- DMA Channel Destination Address registers
#define 	rDMACC3LLI          (*(volatile unsigned long *)  0x50004168) //-- DMA Channel Linked List Item registers
#define 	rDMACC3Control      (*(volatile unsigned long *)  0x5000416C) //-- DMA channel control registers
#define 	rDMACC3Config       (*(volatile unsigned long *)  0x50004170) //-- DMA Channel Configuration registers

#define 	rDMACC4SrcAddr      (*(volatile unsigned long *)  0x50004180) //-- DMA Channel Source Address registers
#define 	rDMACC4DestAddr     (*(volatile unsigned long *)  0x50004184) //-- DMA Channel Destination Address registers
#define 	rDMACC4LLI          (*(volatile unsigned long *)  0x50004188) //-- DMA Channel Linked List Item registers
#define 	rDMACC4Control      (*(volatile unsigned long *)  0x5000418C) //-- DMA channel control registers
#define 	rDMACC4Config       (*(volatile unsigned long *)  0x50004190) //-- DMA Channel Configuration registers

#define 	rDMACC5SrcAddr      (*(volatile unsigned long *)  0x500041A0) //-- DMA Channel Source Address registers
#define 	rDMACC5DestAddr     (*(volatile unsigned long *)  0x500041A4) //-- DMA Channel Destination Address registers
#define 	rDMACC5LLI          (*(volatile unsigned long *)  0x500041A8) //-- DMA Channel Linked List Item registers
#define 	rDMACC5Control      (*(volatile unsigned long *)  0x500041AC) //-- DMA channel control registers
#define 	rDMACC5Config       (*(volatile unsigned long *)  0x500041B0) //-- DMA Channel Configuration registers

#define 	rDMACC6SrcAddr      (*(volatile unsigned long *)  0x500041C0) //-- DMA Channel Source Address registers
#define 	rDMACC6DestAddr     (*(volatile unsigned long *)  0x500041C4) //-- DMA Channel Destination Address registers
#define 	rDMACC6LLI          (*(volatile unsigned long *)  0x500041C8) //-- DMA Channel Linked List Item registers
#define 	rDMACC6Control      (*(volatile unsigned long *)  0x500041CC) //-- DMA channel control registers
#define 	rDMACC6Config       (*(volatile unsigned long *)  0x500041D0) //-- DMA Channel Configuration registers

#define 	rDMACC7SrcAddr      (*(volatile unsigned long *)  0x500041E0) //-- DMA Channel Source Address registers
#define 	rDMACC7DestAddr     (*(volatile unsigned long *)  0x500041E4) //-- DMA Channel Destination Address registers
#define 	rDMACC7LLI          (*(volatile unsigned long *)  0x500041E8) //-- DMA Channel Linked List Item registers
#define 	rDMACC7Control      (*(volatile unsigned long *)  0x500041EC) //-- DMA channel control registers
#define 	rDMACC7Config       (*(volatile unsigned long *)  0x500041F0) //-- DMA Channel Configuration registers

//---- Cortex-M3  core

#define         __NVIC_PRIO_BITS    4         /*!< standard definition for NVIC Priority Bits */

typedef enum IRQn
{
   /******  Cortex-M3 Processor Exceptions Numbers ***************************************************/

  NonMaskableInt_IRQn           = -14,      /*!< 2 Non Maskable Interrupt                         */
  MemoryManagement_IRQn         = -12,      /*!< 4 Cortex-M3 Memory Management Interrupt          */
  BusFault_IRQn                 = -11,      /*!< 5 Cortex-M3 Bus Fault Interrupt                  */
  UsageFault_IRQn               = -10,      /*!< 6 Cortex-M3 Usage Fault Interrupt                */
  SVCall_IRQn                   = -5,       /*!< 11 Cortex-M3 SV Call Interrupt                   */
  DebugMonitor_IRQn             = -4,       /*!< 12 Cortex-M3 Debug Monitor Interrupt             */
  PendSV_IRQn                   = -2,       /*!< 14 Cortex-M3 Pend SV Interrupt                   */
  SysTick_IRQn                  = -1,       /*!< 15 Cortex-M3 System Tick Interrupt               */

  /******  LPC17xx Specific Interrupt Numbers *******************************************************/

  WDT_IRQn                      = 0,        /*!< Watchdog Timer Interrupt                         */
  TIMER0_IRQn                   = 1,        /*!< Timer0 Interrupt                                 */
  TIMER1_IRQn                   = 2,        /*!< Timer1 Interrupt                                 */
  TIMER2_IRQn                   = 3,        /*!< Timer2 Interrupt                                 */
  TIMER3_IRQn                   = 4,        /*!< Timer3 Interrupt                                 */
  UART0_IRQn                    = 5,        /*!< UART0 Interrupt                                  */
  UART1_IRQn                    = 6,        /*!< UART1 Interrupt                                  */
  UART2_IRQn                    = 7,        /*!< UART2 Interrupt                                  */
  UART3_IRQn                    = 8,        /*!< UART3 Interrupt                                  */
  PWM1_IRQn                     = 9,        /*!< PWM1 Interrupt                                   */
  I2C0_IRQn                     = 10,       /*!< I2C0 Interrupt                                   */
  I2C1_IRQn                     = 11,       /*!< I2C1 Interrupt                                   */
  I2C2_IRQn                     = 12,       /*!< I2C2 Interrupt                                   */
  SPI_IRQn                      = 13,       /*!< SPI Interrupt                                    */
  SSP0_IRQn                     = 14,       /*!< SSP0 Interrupt                                   */
  SSP1_IRQn                     = 15,       /*!< SSP1 Interrupt                                   */
  PLL0_IRQn                     = 16,       /*!< PLL0 Lock (Main PLL) Interrupt                   */
  RTC_IRQn                      = 17,       /*!< Real Time Clock Interrupt                        */
  EINT0_IRQn                    = 18,       /*!< External Interrupt 0 Interrupt                   */
  EINT1_IRQn                    = 19,       /*!< External Interrupt 1 Interrupt                   */
  EINT2_IRQn                    = 20,       /*!< External Interrupt 2 Interrupt                   */
  EINT3_IRQn                    = 21,       /*!< External Interrupt 3 Interrupt                   */
  ADC_IRQn                      = 22,       /*!< A/D Converter Interrupt                          */
  BOD_IRQn                      = 23,       /*!< Brown-Out Detect Interrupt                       */
  USB_IRQn                      = 24,       /*!< USB Interrupt                                    */
  CAN_IRQn                      = 25,       /*!< CAN Interrupt                                    */
  DMA_IRQn                      = 26,       /*!< General Purpose DMA Interrupt                    */
  I2S_IRQn                      = 27,       /*!< I2S Interrupt                                    */
  ENET_IRQn                     = 28,       /*!< Ethernet Interrupt                               */
  RIT_IRQn                      = 29,       /*!< Repetitive Interrupt Timer Interrupt             */
  MCPWM_IRQn                    = 30,       /*!< Motor Control PWM Interrupt                      */
  QEI_IRQn                      = 31,       /*!< Quadrature Encoder Interface Interrupt           */
  PLL1_IRQn                     = 32,       /*!< PLL1 Lock (USB PLL) Interrupt                    */
} IRQn_Type;

/* memory mapping struct for Nested Vectored Interrupt Controller (NVIC) */

typedef struct
{
   volatile unsigned int ISER[8];                      /*!< Interrupt Set Enable Register            */
   unsigned int RESERVED0[24];
   volatile unsigned int ICER[8];                      /*!< Interrupt Clear Enable Register          */
   unsigned int RSERVED1[24];
   volatile unsigned int ISPR[8];                      /*!< Interrupt Set Pending Register           */
   unsigned int RESERVED2[24];
   volatile unsigned int ICPR[8];                      /*!< Interrupt Clear Pending Register         */
   unsigned int RESERVED3[24];
   volatile unsigned int IABR[8];                      /*!< Interrupt Active bit Register            */
   unsigned int RESERVED4[56];
   volatile unsigned char IP[240];                      /*!< Interrupt Priority Register, 8Bit wide   */
   unsigned int RESERVED5[644];
   volatile unsigned int STIR;                         /*!< Software Trigger Interrupt Register      */
}NVIC_Type;

/* memory mapping struct for System Control Block */

typedef struct
{
  volatile unsigned int CPUID;                        /*!< CPU ID Base Register                                     */
  volatile unsigned int ICSR;                         /*!< Interrupt Control State Register                         */
  volatile unsigned int VTOR;                         /*!< Vector Table Offset Register                             */
  volatile unsigned int AIRCR;                        /*!< Application Interrupt / Reset Control Register           */
  volatile unsigned int SCR;                          /*!< System Control Register                                  */
  volatile unsigned int CCR;                          /*!< Configuration Control Register                           */
  volatile unsigned char SHP[12];                     /*!< System Handlers Priority Registers (4-7, 8-11, 12-15)    */
  volatile unsigned int SHCSR;                        /*!< System Handler Control and State Register                */
  volatile unsigned int CFSR;                         /*!< Configurable Fault Status Register                       */
  volatile unsigned int HFSR;                         /*!< Hard Fault Status Register                               */
  volatile unsigned int DFSR;                         /*!< Debug Fault Status Register                              */
  volatile unsigned int MMFAR;                        /*!< Mem Manage Address Register                              */
  volatile unsigned int BFAR;                         /*!< Bus Fault Address Register                               */
  volatile unsigned int AFSR;                         /*!< Auxiliary Fault Status Register                          */
  volatile unsigned int PFR[2];                       /*!< Processor Feature Register                               */
  volatile unsigned int DFR;                          /*!< Debug Feature Register                                   */
  volatile unsigned int ADR;                          /*!< Auxiliary Feature Register                               */
  volatile unsigned int MMFR[4];                      /*!< Memory Model Feature Register                            */
  volatile unsigned int ISAR[5];                      /*!< ISA Feature Register                                     */
}SCB_Type;


/* memory mapping struct for SysTick */

typedef struct
{
  volatile unsigned int CTRL;                         /*!< SysTick Control and Status Register */
  volatile unsigned int LOAD;                         /*!< SysTick Reload Value Register       */
  volatile unsigned int VAL;                          /*!< SysTick Current Value Register      */
  volatile unsigned int CALIB;                        /*!< SysTick Calibration Register        */
}SysTick_Type;


/* Memory mapping of Cortex-M3 Hardware */

#define SCS_BASE            (0xE000E000)                              /*!< System Control Space Base Address    */
#define ITM_BASE            (0xE0000000)                              /*!< ITM Base Address                     */
#define CoreDebug_BASE      (0xE000EDF0)                              /*!< Core Debug Base Address              */
#define SysTick_BASE        (SCS_BASE +  0x0010)                      /*!< SysTick Base Address                 */
#define NVIC_BASE           (SCS_BASE +  0x0100)                      /*!< NVIC Base Address                    */
#define SCB_BASE            (SCS_BASE +  0x0D00)                      /*!< System Control Block Base Address    */

#define InterruptType       ((InterruptType_Type *) SCS_BASE)         /*!< Interrupt Type Register              */
#define SCB                 ((SCB_Type *)           SCB_BASE)         /*!< SCB configuration struct             */
#define SysTick             ((SysTick_Type *)       SysTick_BASE)     /*!< SysTick configuration struct         */
#define NVIC                ((NVIC_Type *)          NVIC_BASE)        /*!< NVIC configuration struct            */
#define ITM                 ((ITM_Type *)           ITM_BASE)         /*!< ITM configuration struct             */
#define CoreDebug           ((CoreDebug_Type *)     CoreDebug_BASE)   /*!< Core Debug configuration struct      */

// System Reset

#define NVIC_VECTRESET                    0      //-- Vector Reset Bit
#define NVIC_SYSRESETREQ                  2      //-- System Reset Request
#define NVIC_AIRCR_VECTKEY     (0x5FA << 16)     //-- AIRCR Key for write access
#define NVIC_AIRCR_ENDIANESS             15      //-- Endianess

// Core Debug

#define CoreDebug_DEMCR_TRCENA    (1 << 24)      //-- DEMCR TRCENA enable
#define ITM_TCR_ITMENA                   1       //-- ITM enable

//---- Flash

#define 	rMEMMAP   (*(volatile unsigned long *)  0x400FC040) //-- Memory Mapping Control register


    //---- lpc17xx_core.c

void NVIC_SetPriorityGrouping(unsigned int PriorityGroup);
unsigned int NVIC_GetPriorityGrouping(void);
void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
unsigned int NVIC_GetPendingIRQ(IRQn_Type IRQn);
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
unsigned int NVIC_GetActive(IRQn_Type IRQn);
void NVIC_SetPriority(IRQn_Type IRQn, unsigned int priority);
unsigned int NVIC_GetPriority(IRQn_Type IRQn);
unsigned int NVIC_EncodePriority (unsigned int PriorityGroup, unsigned int PreemptPriority, unsigned int SubPriority);
void NVIC_DecodePriority (unsigned int Priority, unsigned int PriorityGroup, unsigned int* pPreemptPriority, unsigned int* pSubPriority);
unsigned int SysTick_Config(unsigned int ticks);
void NVIC_SystemReset(void);

//-------------------------------
#endif


