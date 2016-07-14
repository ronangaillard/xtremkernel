   .cpu cortex-m3
   .section .text
   .code 16
   .syntax unified
 
  /* External references */

  .extern   current_running_task
  .extern   next_task_to_run
  .extern   system_state
 
  /* Public functions declared in this file */

  .global  switch_context_exit
  .global  switch_context
  .global  cpu_save_sr
  .global  cpu_restore_sr
  .global  launch_os
  .global  chk_irq_disabled
  .global  PendSV_Handler
  .global  int_exit
  .global  ffs_asm
  
  .global  arm_disable_interrupt
  .global  arm_enable_interrupt

 



 /*  Interrupt Control State Register Address */

  .equ ICSR_ADDR,   0xE000ED04

 /*  pendSV bit in the Interrupt Control State Register */

  .equ PENDSVSET,   0x10000000

 /*  System Handlers 12-15 Priority Register Address */

  .equ PR_12_15_ADDR,  0xE000ED20

 /*  PRI_14 (PendSV) priority in the System Handlers 12-15 Priority Register Address
     PendSV priority is minimal (0xFF)
 */

  .equ PENDS_VPRIORITY,  0x00FF0000

/*----------------------------------------------------------------------------*
/* Interrups not yet enabled */
/*--------------------------------------------------------------------------- */
 .thumb_func

launch_os:
       //cpsid   I


       ldr    r1, =PR_12_15_ADDR        /* Load the System 12-15 Priority Register */
       ldr    r0, [r1]
       orr    r0, r0, #PENDS_VPRIORITY  /*  set PRI_14 (PendSV) to 0xFF - minimal */
       str    r0, [r1]

       ldr    r1, =system_state      /*  Indicate that system has started */
       mov    r0, #1                    /*  1 -> SYS_STATE_RUNNING */
       strb   r0, [r1]

  /*---------------*/

       ldr    r1, =current_running_task     /*  =next_task_to_run */
       ldr    r2, [r1]
       ldr    r0, [r2]                  /*  in r0 - new task SP */

       ldmia  r0!, {r4-r11}
       msr    psp, r0
       orr    lr, lr, #0x04             /*  Force to new process PSP */

/* switch_context_exit: */

       ldr    r1, =ICSR_ADDR            /*  Trigger PendSV exception */
       ldr    r0, =PENDSVSET
       str    r0, [r1]
       //bx     lr
       cpsie  I                         /*  Enable core interrupts */

  /* - Never reach this  */
       bx     lr
       b  .
    /*  bx lr */


/* ------------------------------------------------------------------------ */
  .thumb_func

switch_context_exit:

    

  /*  At the interrupt request below, the PSP will be used to
     store manually saved 8 registers (r4-r11) */

       ldr    r1,  =current_running_task
       ldr    r2,  [r1]
       ldr    r0,  [r2]       /* in r0 - cur_run_task stack */

  /*  Preset PSP stack */

       add    r0,  r0, #32    /* 8*4 - 8 manually saved registers */
       msr    psp, r0

  /*  At the interrupt request below, the MSP will be used
      to store automaticaly saved 8 registers */

  /* Preset MSP stack */

       mrs    r0,  msp
       adds   r0,  r0, #32   /* 8*4 - 8 automatically saved registers at the PendSV interrupt */
       msr    msp, r0

       mov    r0,  #0        /* Default stack MSP(Main stack pointer) is used */
       msr    control, r0

  /* ------------------------------- */

      ldr    r1,  =ICSR_ADDR           /*  Trigger PendSV exception */
      ldr    r0,  =PENDSVSET
      str    r0,  [r1]

      cpsie  I                         /*  Enable core interrupts */

  /* - Should never reach  */

       b  .


/* ------------------------------------------------------------------------ */

    .thumb_func

PendSV_Handler:

       cpsid  I                         //Disable core interruption

	//First we compare the next_task_to_run pointer to the current_running task pointer
       ldr    r3, =current_running_task          
       ldr    r1, [r3]                      
       ldr    r2, =next_task_to_run
       ldr    r2, [r2]                       
       cmp    r1, r2						//If next task to run and current task are the save there is nothing ot do, let's just exit context switching
       beq    exit_context_switch



       mrs    r0, psp                   //Moves PSP to R0
       stmdb  r0!, {r4-r11}				//Save registers of current running task to stack (non pushed by NVIC)

       str    r0, [r1]                  //Saves SP to Task Structure (TCB) (in r1 address of current running task TCB)
       str    r2, [r3]                  //In r3 address of current_running task, current_running_task <- next_task_to_run
       ldr    r0, [r2]                  //r2 contains new SP

       ldmia  r0!, {r4-r11}				//Restore previously saved registers (of new task)
       msr    psp, r0					//Moves RO to PSP
       orr    lr, lr, #0x04             //lr <- lr | 0x04; forces to use PSP on return of interrupt



exit_context_switch:

       cpsie  I                         //Enable core interruption

       bx     lr

/* ------------------------------------------------------------------------ */
  .thumb_func

switch_context:

     /* -  Just Invoke PendSV exception   */

       ldr    r1, =ICSR_ADDR
       ldr    r0, =PENDSVSET
       str    r0, [r1]

       bx     lr

/* ------------------------------------------------------------------------ */
  .thumb_func

int_exit:

       ldr    r1, =ICSR_ADDR            /*  Invoke PendSV exception  */
       ldr    r0, =PENDSVSET
       str    r0, [r1]

       bx     lr

/* ------------------------------------------------------------------------ */
  .thumb_func

cpu_save_sr:

       mrs    r0, primask
       cpsid  I
       bx     lr

/* ------------------------------------------------------------------------ */
  .thumb_func

cpu_restore_sr:

       msr    primask, r0
       bx     lr

/* ------------------------------------------------------------------------ */
  .thumb_func

chk_irq_disabled:

       mrs    r0, primask
       bx     lr

/* ------------------------------------------------------------------------ */
  .thumb_func

ffs_asm:

       mov    r1, r0                    /*  tmp = in  */
       rsbs   r0, r1, #0                /*  in = -in  */
       ands   r0, r0, r1                /*  in = in & tmp  */
       CLZ.W  r0, r0
       rsb    r0, r0, #0x20             /*  32 - in */

       bx     lr

/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------- */
  .thumb_func

arm_disable_interrupt:

     cpsid  I
     bx     lr


/* ------------------------------------------------------------------------- */
  .thumb_func

arm_enable_interrupt:

     cpsie I
     bx   lr

    

  .end
