
/******************************************************************************
 * @file:    core_cm3.h
 * @purpose: CMSIS Cortex-M3 Core Peripheral Access Layer Header File
 * @version: V1.20
 * @date:    22. May 2009
 *----------------------------------------------------------------------------
 *
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * ARM Limited (ARM) is supplying this software for use with Cortex-Mx
 * processor based microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such ARM based processors.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#include "LPC176x.h"

/* ##########################   NVIC functions  #################################### */

/**
 * @brief  Set the Priority Grouping in NVIC Interrupt Controller
 *
 * @param  uint32_t priority_grouping is priority grouping field
 * @return none 
 *
 * Set the priority grouping field using the required unlock sequence.
 * The parameter priority_grouping is assigned to the field 
 * SCB->AIRCR [10:8] PRIGROUP field. Only values from 0..7 are used.
 * In case of a conflict between priority grouping and available
 * priority bits (__NVIC_PRIO_BITS) the smallest possible priority group is set.
 */

void NVIC_SetPriorityGrouping(unsigned int PriorityGroup)
{
  unsigned int reg_value;
  unsigned int PriorityGroupTmp = (PriorityGroup & 0x07);                         /* only values 0..7 are used          */

  reg_value  = SCB->AIRCR;                                                    /* read old register configuration    */
  reg_value &= ~((0xFFFFU << 16) | (0x0F << 8));                              /* clear bits to change               */
  reg_value  = ((reg_value | NVIC_AIRCR_VECTKEY | (PriorityGroupTmp << 8)));  /* Insert write key and priorty group */
  SCB->AIRCR = reg_value;
}

/** * @brief  Get the Priority Grouping from NVIC Interrupt Controller
 *
 * @param  none
 * @return unsigned int   priority grouping field
 *
 * Get the priority grouping from NVIC Interrupt Controller.
 * priority grouping is SCB->AIRCR [10:8] PRIGROUP field.
 */

unsigned int NVIC_GetPriorityGrouping(void)
{
  return ((SCB->AIRCR >> 8) & 0x07);                                          /* read priority grouping field */
}

/**
 * @brief  Enable Interrupt in NVIC Interrupt Controller
 *
 * @param  IRQn_Type IRQn specifies the interrupt number
 * @return none
 *
 * Enable a device specific interupt in the NVIC interrupt controller.
 * The interrupt number cannot be a negative value.
 */

void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  NVIC->ISER[((unsigned int)(IRQn) >> 5)] = (1 << ((unsigned int)(IRQn) & 0x1F)); /* enable interrupt */
}


/**
 * @brief  Disable the interrupt line for external interrupt specified
 *
 * @param  IRQn_Type IRQn is the positive number of the external interrupt
 * @return none
 *
 * Disable a device specific interupt in the NVIC interrupt controller.
 * The interrupt number cannot be a negative value.
 */

void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  NVIC->ICER[((unsigned int)(IRQn) >> 5)] = (1 << ((unsigned int)(IRQn) & 0x1F)); /* disable interrupt */
}

/**
 * @brief  Read the interrupt pending bit for a device specific interrupt source
 *
 * @param  IRQn_Type IRQn is the number of the device specifc interrupt
 * @return unsigned int 1 if pending interrupt else 0
 *
 * Read the pending register in NVIC and return 1 if its status is pending,
 * otherwise it returns 0
 */

unsigned int NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((unsigned int) ((NVIC->ISPR[(unsigned int)(IRQn) >> 5] & (1 << ((unsigned int)(IRQn) & 0x1F)))?1:0)); /* Return 1 if pending else 0 */
}

/**
 * @brief  Set the pending bit for an external interrupt
 *
 * @param  IRQn_Type IRQn is the Number of the interrupt
 * @return none
 *
 * Set the pending bit for the specified interrupt.
 * The interrupt number cannot be a negative value.
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ISPR[((unsigned int)(IRQn) >> 5)] = (1 << ((unsigned int)(IRQn) & 0x1F)); /* set interrupt pending */
}

/**
 * @brief  Clear the pending bit for an external interrupt
 *
 * @param  IRQn_Type IRQn is the Number of the interrupt
 * @return none
 *
 * Clear the pending bit for the specified interrupt.
 * The interrupt number cannot be a negative value.
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ICPR[((unsigned int)(IRQn) >> 5)] = (1 << ((unsigned int)(IRQn) & 0x1F)); /* Clear pending interrupt */
}

/**
 * @brief  Read the active bit for an external interrupt
 *
 * @param  IRQn_Type  IRQn is the Number of the interrupt
 * @return unsigned int   1 if active else 0
 *
 * Read the active register in NVIC and returns 1 if its status is active,
 * otherwise it returns 0.
 */
unsigned int NVIC_GetActive(IRQn_Type IRQn)
{
  return((unsigned int)((NVIC->IABR[(unsigned int)(IRQn) >> 5] & (1 << ((unsigned int)(IRQn) & 0x1F)))?1:0)); /* Return 1 if active else 0 */
}

/**
 * @brief  Set the priority for an interrupt
 *
 * @param  IRQn_Type IRQn is the Number of the interrupt
 * @param  priority is the priority for the interrupt
 * @return none
 *
 * Set the priority for the specified interrupt. The interrupt
 * number can be positive to specify an external (device specific)
 * interrupt, or negative to specify an internal (core) interrupt. \n
 *
 * Note: The priority cannot be set for every core interrupt.
 */
void NVIC_SetPriority(IRQn_Type IRQn, unsigned int priority)
{
  if(IRQn < 0) {
    SCB->SHP[((unsigned int)(IRQn) & 0xF)-4] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff); } /* set Priority for Cortex-M3 System Interrupts */
  else {
    NVIC->IP[(unsigned int)(IRQn)] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff);    }        /* set Priority for device specific Interrupts      */
}

/**
 * @brief  Read the priority for an interrupt
 *
 * @param  IRQn_Type IRQn is the Number of the interrupt
 * @return unsigned int  priority is the priority for the interrupt
 *
 * Read the priority for the specified interrupt. The interrupt
 * number can be positive to specify an external (device specific)
 * interrupt, or negative to specify an internal (core) interrupt.
 *
 * The returned priority value is automatically aligned to the implemented
 * priority bits of the microcontroller.
 *
 * Note: The priority cannot be set for every core interrupt.
 */
unsigned int NVIC_GetPriority(IRQn_Type IRQn)
{
   if(IRQn < 0)
   {
      return((unsigned int)(SCB->SHP[((unsigned int)(IRQn) & 0xF)-4] >> (8 - __NVIC_PRIO_BITS)));  /* get priority for Cortex-M3 system interrupts */
   }
   else 
   {
      return((unsigned int)(NVIC->IP[(unsigned int)(IRQn)]           >> (8 - __NVIC_PRIO_BITS)));  /* get priority for device specific interrupts  */
   }
}


/**
 * @brief  Encode the priority for an interrupt
 *
 * @param  unsigned int PriorityGroup   is the used priority group
 * @param  unsigned int PreemptPriority is the preemptive priority value (starting from 0)
 * @param  unsigned int SubPriority     is the sub priority value (starting from 0)
 * @return unsigned int                    the priority for the interrupt
 *
 * Encode the priority for an interrupt with the given priority group,
 * preemptive priority value and sub priority value.
 * In case of a conflict between priority grouping and available
 * priority bits (__NVIC_PRIO_BITS) the samllest possible priority group is set.
 *
 * The returned priority value can be used for NVIC_SetPriority(...) function
 */
unsigned int NVIC_EncodePriority (unsigned int PriorityGroup, unsigned int PreemptPriority, unsigned int SubPriority)
{
  unsigned int PriorityGroupTmp = (PriorityGroup & 0x07);                         /* only values 0..7 are used          */
  unsigned int PreemptPriorityBits;
  unsigned int SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > __NVIC_PRIO_BITS) ? __NVIC_PRIO_BITS : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + __NVIC_PRIO_BITS) < 7) ? 0 : PriorityGroupTmp - 7 + __NVIC_PRIO_BITS;

  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}


/**
 * @brief  Decode the priority of an interrupt
 *
 * @param  unsigned int   Priority       the priority for the interrupt
 * @param  unsigned int   PrioGroup   is the used priority group
 * @param  unsigned int* pPreemptPrio is the preemptive priority value (starting from 0)
 * @param  unsigned int* pSubPrio     is the sub priority value (starting from 0)
 * @return none
 *
 * Decode an interrupt priority value with the given priority group to
 * preemptive priority value and sub priority value.
 * In case of a conflict between priority grouping and available
 * priority bits (__NVIC_PRIO_BITS) the samllest possible priority group is set.
 *
 * The priority value can be retrieved with NVIC_GetPriority(...) function
 */
void NVIC_DecodePriority (unsigned int Priority, unsigned int PriorityGroup, unsigned int* pPreemptPriority, unsigned int* pSubPriority)
{
  unsigned int PriorityGroupTmp = (PriorityGroup & 0x07);                         /* only values 0..7 are used          */
  unsigned int PreemptPriorityBits;
  unsigned int SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > __NVIC_PRIO_BITS) ? __NVIC_PRIO_BITS : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + __NVIC_PRIO_BITS) < 7) ? 0 : PriorityGroupTmp - 7 + __NVIC_PRIO_BITS;

  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}



/* ##################################    SysTick function  ############################################ */


/* SysTick constants */

#define SYSTICK_ENABLE              0                                          /* Config-Bit to start or stop the SysTick Timer                         */
#define SYSTICK_TICKINT             1                                          /* Config-Bit to enable or disable the SysTick interrupt                 */
#define SYSTICK_CLKSOURCE           2                                          /* Clocksource has the offset 2 in SysTick Control and Status Register   */
#define SYSTICK_MAXCOUNT       ((1<<24) -1)                                    /* SysTick MaxCount                                                      */

/**
 * @brief  Initialize and start the SysTick counter and its interrupt.
 *
 * @param  unsigned int ticks is the number of ticks between two interrupts
 * @return  none
 *
 * Initialise the system tick timer and its interrupt and start the
 * system tick timer / counter in free running mode to generate
 * periodical interrupts.
 */
unsigned int SysTick_Config(unsigned int ticks)
{
  if(ticks > SYSTICK_MAXCOUNT)
     return 1;                                             /* Reload value impossible */

  SysTick->LOAD  =  (ticks & SYSTICK_MAXCOUNT) - 1;                                      /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);                            /* set Priority for Cortex-M0 System Interrupts */
  SysTick->VAL   =  (0x00);                                                              /* Load the SysTick Counter Value */
  SysTick->CTRL = (1 << SYSTICK_CLKSOURCE) | (1<<SYSTICK_ENABLE) | (1<<SYSTICK_TICKINT); /* Enable SysTick IRQ and SysTick Timer */

  return 0;                                                                            /* Function successful */
}


/* ##################################    Reset function  ############################################ */

/**
 * @brief  Initiate a system reset request.
 *
 * @param   none
 * @return  none
 *
 * Initialize a system reset request to reset the MCU
 */

void NVIC_SystemReset(void)
{
   //-- Keep priority group unchanged

   SCB->AIRCR  = (NVIC_AIRCR_VECTKEY | (SCB->AIRCR & (0x700)) | (1<<NVIC_SYSRESETREQ)); 

#if defined  ( __CC_ARM )         //-- RealView Compiler 
   __dsb(0);   
#elif (defined ( __GNUC__ ))      //-- GNU Compiler
   { __asm volatile ("dsb"); }
#endif

   while(1);   //-- wait until reset 
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------







