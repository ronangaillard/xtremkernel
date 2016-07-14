    .section .text
    .code 16
    .syntax unified


    .equ  PCLKSEL0, 0x400FC1A8  /* PCLKSEL0 */

  /* -- Public functions declared in this file */

     .global  startup_hardware_init
     .global  arm_disable_interrupts
     .global  arm_enable_interrupts

/* ----------------------------------------------------------------------------
; This routine starts/inits everything for the processor
; These are only the vital parts, less vital parts will be done in the C code
---------------------------------------------------------------------------- */
  .thumb_func

startup_hardware_init:

    /* PCLKSEL0 - UART0, SPI, Timer 1 (MAT1.1), PWM1 (PWM1.3) */

     ldr    r1, =PCLKSEL0
     ldr    r0, [r1]
     orr    r0, r0, #0x01000000
     orr    r0, r0, #(1<<6)   /* UART0   - Bits 7:6   = 01;  PCLK_peripheral = CCLK */
     orr    r0, r0, #(1<<16)  /* SPI     - Bits 17:16 = 01;  PCLK_peripheral = CCLK */
     orr    r0, r0, #(1<<4)   /* Timer 1 - Bits 5:4   = 01;  PCLK_peripheral = CCLK */
     orr    r0, r0, #(1<<12)  /* PWM1    - Bits 13:12 = 01;  PCLK_peripheral = CCLK */
     str    r0, [r1]

     bx      lr

/* ------------------------------------------------------------------------- */
  .thumb_func

arm_disable_interrupts:

     cpsid  I
     bx     lr


/* ------------------------------------------------------------------------- */
  .thumb_func

arm_enable_interrupts:

     cpsie I
     bx   lr

     .end

/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */




