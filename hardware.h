#ifndef HARDWARE_H
#define HARDWARE_H

#include "types.h"
#include "kernel.h"

#define align_attr_end     __attribute__((aligned(0x8)))
//#define align_attr_end

#define  INTSAVE_DATA_INT     int save_status_reg = 0; 
#define  INTSAVE_DATA         int save_status_reg = 0;

#define  disable_interrupt()  save_status_reg = cpu_save_sr()
#define  enable_interrupt()   cpu_restore_sr(save_status_reg)

void arm_disable_interrupt(void);
//----------------------------------------------------------------------
//NVIC
//----------------------------------------------------------------------

#define  rNVIC_ICSR      (*((volatile unsigned int*)0xE000ED04))
#define  VECTACTIVE      (0x000001FF)



#define  PLL0CFG_VAL              11  /* 11+1  */
#define  CCLKCFG_VAL               2  /* 2+1  */

BOOL inside_interrupt(void);//Tells if we are inside an interupt or not; see Cortex M3 guide for further references

#define  idisable_interrupt() save_status_reg = cpu_save_sr()
#define  ienable_interrupt()  cpu_restore_sr(save_status_reg)


unsigned int * stack_init(void * task_func,
                             void * stack_start,
                             void * param);//??
                             
#define  CHECK_INT_CONTEXT   \
             if(!inside_interrupt()) \
                return TERR_WCONTEXT;

#define  CHECK_INT_CONTEXT_NORETVAL  \
             if(!inside_interrupt())     \
                return;

#define  CHECK_NON_INT_CONTEXT   \
             if(inside_interrupt()) \
                return ERR_WRONG_CONTEXT;

#define  CHECK_NON_INT_CONTEXT_NORETVAL   \
             if(inside_interrupt()) \
                return ;

#endif
