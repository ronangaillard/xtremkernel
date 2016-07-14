
#include "strucutres.h"
#include "mutex.h"


//In the XTrem Kernel considers there is no deadlock possible and for the moment impents no deadlock avoidance

int create_mutex(MUTEX * mutex)
{


   if(mutex == NULL)
      return ERR_WRONG_PARAMETER;

   if(attribute != MUTEX_ATTR_CEILING && attribute != MUTEX_ATTR_INHERIT)
      return ERR_WRONG_PARAMETER;
   if(attribute == MUTEX_ATTR_CEILING &&
         (ceil_priority < 1 || ceil_priority > NUM_PRIORITY - 2))
      return ERR_WRONG_PARAMETER;


   queue_reset(&(mutex->wait_queue));
   queue_reset(&(mutex->mutex_queue));
   queue_reset(&(mutex->lock_mutex_queue));

   mutex->attr          = attribute;
   mutex->holder        = NULL;
   mutex->ceil_priority = ceil_priority;
   mutex->cnt           = 0;


   return ERR_NO_ERROR;
}

//----------------------------------------------------------------------------
int delete_mutex(MUTEX * mutex)
{
   INTSAVE_DATA

   QUEUE * que;
   TASK * task;


   if(mutex == NULL)
      return ERR_WRONG_PARAMETER;



   CHECK_NON_INT_CONTEXT
    
   if(current_running_task != mutex->holder)
      return ERR_ILLEGAL_USE;

 

   disable_interrupt(); 
//We need to remove all tasks from wait queue
   while(!is_queue_empty(&(mutex->wait_queue)))
   {
      que  = queue_remove_next(&(mutex->wait_queue));
      task = get_task_by_task_queue(que);

    //-- If the task in system's blocked list, remove it

      if(task_wait_complete(task))
      {
         task->task_wait_return_code = ERR_DLT;
         enable_interrupt();
         switch_context();
         disable_interrupt(); 
      }
   }

   if(mutex->holder != NULL)  //-- If the mutex is locked
   {
      do_unlock_mutex(mutex);
      queue_reset(&(mutex->mutex_queue));
   }


   enable_interrupt();

   return TERR_NO_ERR;
}

//----------------------------------------------------------------------------
int lock_mutex(MUTEX * mutex, unsigned long timeout)
{
   INTSAVE_DATA


   if(mutex == NULL || timeout == 0)
      return ERR_WRONG_PARAMETER;
   


   CHECK_NON_INT_CONTEXT

   disable_interrupt();

   if(current_running_task == mutex->holder) //Mutex already locked
   {
      enable_interrupt();
      return ERR_ILLEGAL_USE;
   }

      if(mutex->holder == NULL) //Mutex not locked : OK!
      {
         mutex->holder = current_running_task;

         queue_insert_previous(&(current_running_task->mutex_queue), &(mutex->mutex_queue));

         enable_interrupt();

         return ERR_NO_ERROR;
      }
      else //-- the mutex is already locked
      {
            //-- Base priority inheritance protocol
            //-- if run_task curr priority higher holder's curr priority

         if(current_running_task->priority < mutex->holder->priority)
            set_current_priority(mutex->holder, current_running_task->priority);

         task_curr_to_wait_action(&(mutex->wait_queue),
                                  TSK_WAIT_REASON_MUTEX_I,
                                  timeout);
         enable_interrupt();
         switch_context();

         return current_running_task->task_wait_return_code;
      }
   

   enable_interrupt(); //-- Never reach
   return ERR_NO_ERROR;
}

//----------------------------------------------------------------------------
//  Try to lock mutex
//----------------------------------------------------------------------------
int try_lock_mutex(MUTEX * mutex)
{
   INTSAVE_DATA
   int return_code;


   if(mutex == NULL)
      return ERR_WRONG_PARAMETER;
   


   CHECK_NON_INT_CONTEXT

   disable_interrupt();

   return_code =ERR_NO_ERROR;
   
      if(current_running_task == mutex->holder) //Already lock by task!
      {
         rc = ERR_ILLEGAL_USE;
         break;
      }else if(mutex->holder == NULL) //-- the mutex is not locked
      {
         mutex->holder = current_running_task;
         queue_insert_before(&(current_running_task->mutex_queue), &(mutex->mutex_queue));

        
      }
      else //-- the mutex is already locked
      {
         return_code = ERR_TIMEOUT;
      }
      
   

   enable_interrupt();

   return return_code;
}

//----------------------------------------------------------------------------
int unlock_mutex(MUTEX * mutex)
{
   QUEUE * curr_que;
   MUTEX * tmp_mutex;
   TASK * task;
   int pr;
   
   INTSAVE_DATA


   if(mutex == NULL)
      return ERR_WRONG_PARAMETER;


   CHECK_NON_INT_CONTEXT

   disable_interrupt();

//Only the locker of the mutex can unlock the mutex

   if(current_running_task != mutex->holder)
   {
      enable_interrupt();
      return ERR_ILLEGAL_USE;
   }


   //Delete current mutex from task's locked mutexes queue

   queue_remove_element(&(mutex->mutex_queue));
   pr = current_running_task->base_priority;

   //No more mutexes, locked by the our task

   if(!is_queue_empty(&(current_running_task->mutex_queue)))
   {
      curr_que = current_running_task->mutex_queue.next;
      while(curr_que != &(current_running_task->mutex_queue))
      {
         tmp_mutex = get_mutex_by_mutex_queue(curr_que);

         
         pr = find_max_blocked_priority(tmp_mutex, pr);
         
         curr_que = curr_que->next;
      }
   }

   //Restore original priority

   if(pr != current_running_task->priority)
      change_running_task_priority(current_running_task, pr);


   //Check for the task(s) that want to lock the mutex

   if(is_queue_empty(&(mutex->wait_queue)))
   {
      mutex->holder = NULL;
      return ERR_NO_ERROR;
   }

   //Now lock the mutex by the first task in the mutex queue

   curr_que = queue_remove_head(&(mutex->wait_queue));
   task     = get_task_by_task_queue(curr_que);
   mutex->holder = task;

   task_wait_complete(task);
   queue_insert_before(&(task->mutex_queue), &(mutex->mutex_queue));

   return ERR_NO_ERROR;
   
   
   
   
   
   enable_interrupt();
   switch_context();

   return ERR_NO_ERROR;
}


//----------------------------------------------------------------------------
int find_max_blocked_priority(MUTEX * mutex, int ref_priority)
{
   int priority;
   QUEUE * curr_que;
   TASK * task;

   priority = ref_priority;
   curr_que = mutex->wait_queue.next;
   while(curr_que != &(mutex->wait_queue))
   {
      task = get_task_by_tsk_queue(curr_que);
      if(task->priority < priority) //task priority is higher
         priority = task->priority;

      curr_que = curr_que->next;
   }

   return priority;
}



