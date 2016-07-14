#include "structures.h"
#include "semaphore.h"
#include "task.h"


int create_semaphore(SEMAPHORE * sem, int start_value, int max_value)
{


   if(sem == NULL) 
      return  ERR_WRONG_PARAMETER;
   if(max_value <= 0 || start_value < 0 || start_value > max_value ) 
   {
      sem->max_count = 0;
      return  ERR_WRONG_PARAMETER;
   }


   CHECK_NON_INT_CONTEXT

   queue_reset(&(sem->wait_queue));

   sem->count     = start_value;
   sem->max_count = max_val;


   return TERR_NO_ERR;
}

//----------------------------------------------------------------------------
int delete_semaphore(SEMAPHORE * sem)
{
   INTSAVE_DATA
   
   QUEUE * que;
   TASK * task;


   if(sem == NULL)
      return TERR_WRONG_PARAM;
  

   CHECK_NON_INT_CONTEXT

   disable_interrupt(); 

   while(!is_queue_empty(&(sem->wait_queue)))
   {
     //delete from the semaphore wait queue

      que = queue_remove_next(&(sem->wait_queue));
      task = get_task_by_task_queue(que);
      if(task_wait_complete(task))
      {
         task->task_wait_return_code = ERR_DLT;
         enable_interrupt();
         switch_context();
         disable_interrupt(); 
      }
   }

   

   enable_interrupt();

   return ERR_NO_ERROR;
}

//----------------------------------------------------------------------------
//  Release Semaphore Resource
//----------------------------------------------------------------------------
int semaphore_signal(SEMAPHORE * sem)
{
   INTSAVE_DATA
   int return_code; 
   QUEUE * que;
   TASK * task;


   if(sem == NULL)
      return  ERR_WRONG_PARAMETER;
   if(sem->max_count == 0)
      return  ERR_WRONG_PARAMETER;


   CHECK_NON_INT_CONTEXT

   disable_interrupt();

   if(!(is_queue_empty(&(sem->wait_queue))))
   {
      //delete from the sem wait queue

      que = queue_remove_head(&(sem->wait_queue));
      task = get_task_by_tsk_queue(que);

      if(task_wait_complete(task))
      {
         enable_interrupt();
         switch_context();

         return TERR_NO_ERR;
      }
      rc = TERR_NO_ERR;
   }
   else
   {
      if(sem->count < sem->max_count)
      {
         sem->count++;
         rc = TERR_NO_ERR;
      }
      else
         rc = TERR_OVERFLOW;
   }

   enable_interrupt();

   return return_code;
}

//----------------------------------------------------------------------------
// Release Semaphore Resource inside Interrupt
//----------------------------------------------------------------------------
int release_semaphore_i(SEMAPHORE * sem)
{
   INTSAVE_DATA_INT
   int return_code;
   QUEUE * que;
   TASK * task;


   if(sem == NULL)
      return  ERR_WRONG_PARAMETER;
   if(sem->max_count == 0)
      return  ERR_WRONG_PARAMETER;


   CHECK_INT_CONTEXT

   idisable_interrupt();

   if(!(is_queue_empty(&(sem->wait_queue))))
   {
      //delete from the sem wait queue

      que = queue_remove_next(&(sem->wait_queue));
      task = get_task_by_task_queue(que);

      if(task_wait_complete(task))
      {
         enable_interrupt();

         return ERR_NO_ERROR;
      }
      return_code = ERR_NO_ERROR;
   }
   else
   {
      if(sem->count < sem->max_count)
      {
         sem->count++;
        return_code = ERR_NO_ERROR;
      }
      else
         return_code = ERR_OVERFLOW;
   }

   ienable_interrupt();

   return return_code;
}

//----------------------------------------------------------------------------
//   Acquire Semaphore Resource
//----------------------------------------------------------------------------
int acquire_semaphore(SEMAPHORE * sem, unsigned long timeout)
{
   INTSAVE_DATA
   int return_code; //-- return code

   if(sem == NULL || timeout == 0)
      return  TERR_WRONG_PARAM;
   if(sem->max_count == 0)
      return  TERR_WRONG_PARAM;


   CHECK_NON_INT_CONTEXT

   disable_interrupt();

   if(sem->count >= 1)
   {
      sem->count--;
      return_code = ERR_NO_ERROR;
   }
   else
   {
      task_current_to_wait_action(&(sem->wait_queue), TSK_WAIT_REASON_SEM, timeout);
      enable_interrupt();
      switch_context();

      return current_running_task->task_wait_return_code;
   }

   enable_interrupt();

   return return_code;
}

//----------------------------------------------------------------------------
//  Acquire(Polling) Semaphore Resource (do not call  in the interrupt)
//----------------------------------------------------------------------------
int acquire_semaphore_polling(SEMAPHORE * sem)
{
   INTSAVE_DATA
   int return_code;


   if(sem == NULL)
      return  TERR_WRONG_PARAM;
   if(sem->max_count == 0)
      return  TERR_WRONG_PARAM;


   CHECK_NON_INT_CONTEXT

   disable_interrupt();

   if(sem->count >= 1)
   {
      sem->count--;
      return_code = ERR_NO_ERROR;
   }
   else
      return_code = TERR_TIMEOUT;

   enable_interrupt();

   return return_code;
}

//----------------------------------------------------------------------------
// Acquire(Polling) Semaphore Resource inside interrupt
//----------------------------------------------------------------------------
int acquire_semaphore_polling_i(SEMAPHORE * sem)
{
   INTSAVE_DATA_INT
   int return_code;

   if(sem == NULL)
      return  TERR_WRONG_PARAM;
   if(sem->max_count == 0)
      return  TERR_WRONG_PARAM;


   CHECK_INT_CONTEXT

   idisable_interrupt();

   if(sem->count >= 1)
   {
      sem->count--;
      return_code = ERR_NO_ERROR;
   }
   else
      return_code = ERR_TIMEOUT;

   ienable_interrupt();

   return return_code;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------


