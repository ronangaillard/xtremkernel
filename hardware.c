#include "hardware.h"
#include "types.h"
#include "task.h"


BOOL inside_interrupt(void)//Tells if we are inside an interupt or not; see Cortex M3 guide for further references
{
   if(rNVIC_ICSR & VECTACTIVE)
      return TRUE;
   return FALSE;
}


unsigned int * stack_init(void * task_func,
                             void * stack_start,
                             void * param)//??
{
   unsigned int * stk;

 //-- filling register's position in the stack - for debugging only

   stk  = (unsigned int *)stack_start;       //-- Load stack pointer

   *stk = 0x01000000L;                       //-- xPSR
   stk--;

   *stk = ((unsigned int)task_func) | 1;     //-- Entry Point (1 for THUMB mode)
   stk--;

   *stk = ((unsigned int)exit_task) | 1;  //-- R14 (LR)    (1 for THUMB mode)
   stk--;

   *stk = 0x12121212L;                       //-- R12
   stk--;

   *stk = 0x03030303L;                       //-- R3
   stk--;

   *stk = 0x02020202L;                       //-- R2
   stk--;

   *stk = 0x01010101L;                       //-- R1
   stk--;

   *stk = (unsigned int)param;               //-- R0 - task's function argument
   stk--;

   *stk = 0x11111111L;                       //-- R11
   stk--;

   *stk = 0x10101010L;                       //-- R10
   stk--;

   *stk = 0x09090909L;                       //-- R9
   stk--;

   *stk = 0x08080808L;                       //-- R8
   stk--;

   *stk = 0x07070707L;                       //-- R7
   stk--;

   *stk = 0x06060606L;                       //-- R6
   stk--;

   *stk = 0x05050505L;                       //-- R5
   stk--;

   *stk = 0x04040404L;                       //-- R4

   return stk;
}



