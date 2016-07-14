#include "structures.h"
#include "constants.h"
#include "types.h"
#include "task.h"
#include "hardware.h"
#include "utilities.h"


extern volatile int system_state;    //-- System state -(running/not running,etc.)
extern QUEUE all_tasks_queue;                       			    //(Circular) list/queue of all tasks

extern volatile int num_tasks;                					    //Number of tasks
extern QUEUE runnable_tasks_list[NUMBER_OF_PRIORITY_LEVELS];       //(Circular) list/queue of all RUNNABLE tasks (in an array, tasks being ordered by their level of priority)
extern volatile unsigned int priority_ready_to_run_bitmap; //A bitmap showing in which priority there are tasks ready to be run

extern QUEUE waiting_timeout_tasks_list;                  			//(Circular) list/queue of tasks waiting for timmeout



extern TASK * current_running_task;                        //The task that is currently running

extern TASK * next_task_to_run;                     //Next task to be run after "context switch"

int create_task(TASK * task,                 //The task's TASK structure
                 void (*task_function)(void *parameters),  //Pointer to the function of the task's function
                 int priority,                    //Priority of the task
                 unsigned int * task_stack_start, //Stack base address (this is the top of the stack for Cortex M3, as stack is descending)
                 int task_stack_size,             //The size of the allocated stack for this stack (in sizeof(void*) which is 4 bytes for the Cortex M3, not in size of bytes)
                 void * parameters,                    //Parameters for the task function
                 int option)                      //Options used for the cration of the task
{
	INTSAVE_DATA
	
   //int save_status_reg = 0;
   int return_code;

   unsigned int * stack_pointer;
   int i;

 
//Just a little check to make sure we are not creating tasks of priority 0 or 31 which are not the Idle task or the Timer task
   if((priority == 0 && ((option & TASK_TIMER) == 0)) ||
       (priority == NUM_PRIORITY-1 && (option & TASK_IDLE) == 0))
      return ERR_WRONG_PARAMETER;

//Another test to make sure we are not creating tasks with too low or too high priority, or that have other bad parameters
   if((priority < 0 || priority > NUM_PRIORITY-1) ||
        task_stack_size < MIN_STACK_SIZE ||
        task_function == NULL || task == NULL || task_stack_start == NULL)
      return ERR_WRONG_PARAMETER;

   return_code = ERR_NO_ERROR;
   
   

   if(inside_interrupt())  //in hardware.c; we should not be inside an interupt
       return ERR_WRONG_CONTEXT;

   if(system_state == STATE_RUNNING)
      disable_interrupt(); //assembly function

   //Init Task structure variables

   task->task_function_address  = (void*)task_function;
   task->task_function_parameters = parameters;
   task->stack_start       = (unsigned int*)task_stack_start;  //Base address of stack
   task->stack_size        = task_stack_size;                  //Size of stack
   task->base_priority   = priority;                         //Task base priority
   task->activate_count  = 0;                                //Activation request count


   //Let's fill the stack with FILL_STACK_VALUE

   for(stack_pointer = task->stack_start,i = 0;i < task->stack_size; i++)
      *stack_pointer-- = FILL_STACK_VALUE;

   task_set_dormant_state(task); //Initialises some variables

   //Let's init the stack

   stack_pointer = stack_init(task->task_function_address,
                             task->stack_start,
                             task->task_function_parameters);

   task->task_stack = stack_pointer;   //Pointer to the bottom of the stack, beacause stack_init() functions adds thigns to the stack, so moves the pointer, we need to update it


   //We can now add the task initialised to the queue of tasks so that one day it gets executed

   queue_insert_before(&all_tasks_queue,&(task->temp_queue)); //We add it at the end of the queue (the queue is circular)
   num_tasks++;

   if((option & TASK_START_ON_CREATION) != 0)
      set_task_as_runnable(task); //set task as runnable to add it to the corresponding queues

   if(system_state == STATE_RUNNING)
      enable_interrupt(); //assembly function

   return return_code;
}


void set_task_as_runnable(TASK * task)
{
   int priority;

   priority          = task->priority;
   task->task_state  = TSK_STATE_RUNNABLE;
   task->wait_queue = NULL;

   //As the task become runnable we need to add it to the runnable queue:

   queue_insert_before(&(runnable_tasks_list[priority]), &(task->task_queue));
   priority_ready_to_run_bitmap |= 1 << priority;

   //if a running task as a lower priority, this task should be run so we add it to the next_task_to_run

   if(priority < next_task_to_run->priority)
      next_task_to_run = task;
}

void task_set_dormant_state(TASK* task) //Set task to a dormant state
{
	     
   reset_queue(&(task->task_queue));
   reset_queue(&(task->timer_queue));
   reset_queue(&(task->mutex_queue));

   task->wait_queue = NULL;

   task->priority    = task->base_priority; 
   task->task_state  = TSK_STATE_DORMANT;   //Task state
   task->task_wait_reason = 0;              //Reason for waiting
   task->task_wait_return_code = ERR_NO_ERROR;


//We are no more waiting for events
   task->event_wait_pattern = 0;                 //Event wait pattern
   task->event_wait_mode    = 0;                 //Event wait mode:  _AND or _OR


   task->data_element     = NULL;              //Store data queue entry,if data queue is full

   task->tick_count    = WAIT_INFINITE;  //Remaining time until timeout
   task->wakeup_count  = 0;                 //Wakeup request count
   task->suspend_count = 0;                 //Suspension count

   task->time_slice_count  = 0;
}




TASK* get_task_from_timer_queue(QUEUE* queue) //A fast code that gets te task from a queue pointer, see schamtics in documentation for a more explicit explanation
{
	return ((TASK *)((unsigned char *)(queue) - (unsigned char *)(&((TASK *)0)->timer_queue)));
}

int task_wait_complete(TASK* task)
{
   int fmutex;
   int curr_priority;
   MUTEX * mutex;
   TASK* mt_holder_task;
   QUEUE * t_queue;

   int return_code = FALSE;

   if(task == NULL)
      return 0;



   t_queue = NULL;
   
   if(task->task_wait_reason == TSK_WAIT_REASON_MUTEX_I ||
         task->task_wait_reason == TSK_WAIT_REASON_MUTEX_C)
   {
      fmutex = TRUE;
      t_queue = task->wait_queue;
   }
   else
      fmutex = FALSE;



   task->wait_queue  = NULL;
   task->task_wait_return_code = ERR_NO_ERROR;

   if(task->tick_count != WAIT_INFINITE)
      queue_remove_element(&(task->timer_queue));

   task->tick_count = WAIT_INFINITE;

   if(!(task->task_state & TSK_STATE_SUSPEND))
   {
      set_task_as_runnable(task);
      return_code = TRUE;
   }
   else  //-- remove WAIT state
      task->task_state = TSK_STATE_SUSPEND;




   if(fmutex)
   {
      mutex = get_mutex_in_wait_queue(t_queue);

      mt_holder_task = mutex->locker;
      if(mt_holder_task != NULL)
      {
         //-- if task was blocked by another task and its pri was changed
         //--  - recalc current priority

         if(mt_holder_task->priority != mt_holder_task->base_priority &&
             mt_holder_task->priority == task->priority)
         {
            curr_priority = find_max_blocked_priority(mutex,
                                             mt_holder_task->base_priority);

            set_current_priority(mt_holder_task, curr_priority);
            return_code = TRUE;
         }
      }
   }


   task->task_wait_reason = 0; //-- Clear wait reason

   return return_code;
}

void current_task_to_wait_state(QUEUE * wait_queue,
                              int wait_reason,
                              unsigned long timeout) //Sets the task to wait 
{
   task_to_non_runnable(current_running_task);

   current_running_task->task_state       = TSK_STATE_WAIT;
   current_running_task->task_wait_reason = wait_reason;
   current_running_task->tick_count       = timeout;

   //We add the task to the wait queue

   if(wait_queue == NULL)
   {
      reset_queue(&(current_running_task->task_queue));
   }
   else
   {
      queue_insert_before(wait_queue, &(current_running_task->task_queue));
      current_running_task->wait_queue = wait_queue;
   }

   //We also addd the task to timer queue

   if(timeout != WAIT_INFINITE)
      queue_insert_before(&waiting_timeout_tasks_list, &(current_running_task->timer_queue));
}

void task_to_non_runnable(TASK * task)
{
   int priority;
   QUEUE * queue;

   priority = task->priority;
   queue = &(runnable_tasks_list[priority]);

   //Removes the task from the running list

   queue_remove_element(&(task->task_queue));

   if(is_queue_empty(queue))  //It means no other tasks for the same priority
   {
      //We remove the bit in the bitmap

      priority_ready_to_run_bitmap &= ~(1<<priority);

      //We find a new task to run then


      find_next_task_to_run(); 
   }
   else //There are runnable taks of the same priority, let's run them
   {
      if(next_task_to_run == task)
         next_task_to_run = get_task_in_task_queue(queue->next);
   }
}

void find_next_task_to_run(void) //#ifdef USE_ASM_FFS
{
   int tmp; //contains the highest priority with a running task


   int i;
   unsigned int mask;



   mask = 1;
   tmp = 0;
   for(i=0; i < NUMBER_OF_BITS_IN_INT; i++)  //For each bit in the bitmap
   {
      if(priority_ready_to_run_bitmap & mask)
      {
         tmp = i;
         break;
      }
      mask = mask<<1;
   }


   next_task_to_run = get_task_in_task_queue(runnable_tasks_list[tmp].next);
}

TASK* get_task_in_task_queue(QUEUE* queue)
{
	return ((TASK *)((unsigned char *)(queue) - (unsigned char *)(&((TASK *)0)->task_queue)));
} 

MUTEX* get_mutex_in_queue(QUEUE* queue)//?? to change to wiat queue
{
	return ((MUTEX *)((unsigned char *)(queue) - (unsigned char *)(&((MUTEX *)0)->wait_queue)));
}

MUTEX* get_mutex_in_wait_queue(QUEUE* queue)//?? to change to wiat queue
{
	return ((MUTEX *)((unsigned char *)(queue) - (unsigned char *)(&((MUTEX *)0)->wait_queue)));
}

MUTEX* get_mutex_in_mutex_queue(QUEUE* queue)
{
	return ((MUTEX *)((unsigned char *)(queue) - (unsigned char *)(&((MUTEX *)0)->mutex_queue)));
}


void task_curr_to_wait_action(QUEUE * wait_que,
                              int wait_reason,
                              unsigned long timeout)//??
{
   task_to_non_runnable(current_running_task);

   current_running_task->task_state       = TSK_STATE_WAIT;
   current_running_task->task_wait_reason = wait_reason;
   current_running_task->tick_count       = timeout;

   //Add to the wait queue  - FIFO

   if(wait_que == NULL) 
   {
      reset_queue(&(current_running_task->task_queue));
   }
   else
   {
      queue_insert_before(wait_que, &(current_running_task->task_queue));
      current_running_task->wait_queue = wait_que;
   }

   //--- Add to the timers queue

   if(timeout != WAIT_INFINITE)
      queue_insert_before(&waiting_timeout_tasks_list, &(current_running_task->timer_queue));
}

void exit_task(int attribut)
{
	/*  
	  The structure is used to force GCC compiler properly locate and use
   	'stack_exp' - thanks to Angelo R. Di Filippo
	*/
   struct  // v.2.7
   {	

      QUEUE * que;
      MUTEX * mutex;

      TASK * task;
      volatile int stack_exp[PORT_STACK_EXPAND_AT_EXIT];
   }data;
	 
   CHECK_NON_INT_CONTEXT_NORETVAL



   //-- Unlock all mutexes, locked by the task


   while(!is_queue_empty(&(current_running_task->mutex_queue)))
   {
      data.que = queue_remove_next(&(current_running_task->mutex_queue));
      data.mutex = get_mutex_in_queue(data.que);
      do_unlock_mutex(data.mutex);
   }


   data.task = current_running_task;
   task_to_non_runnable(current_running_task);

   task_set_dormant_state(data.task);
	 //-- Pointer to task top of stack,when not running
   data.task->task_stack = stack_init(data.task->task_function_address,
                                  data.task->stack_start,
                                  data.task->task_function_parameters);

   if(data.task->activate_count > 0)  //-- Cannot exit
   {
      data.task->activate_count--;
      set_task_as_runnable(data.task);
   }
   else  // V 2.6 Thanks to Alex Borisov
   {
      if(attribut == EXIT_AND_DELETE_TASK)
      {
         queue_remove_element(&(data.task->temp_queue));
         num_tasks--;
         
      }
   }

   switch_context_exit();  // interrupts will be enabled inside switch_context_exit()
}
int find_max_blocked_priority(MUTEX * mutex, int ref_priority)
{
   int priority;
   QUEUE * curr_que;
   TASK * task;

   priority = ref_priority;
   curr_que = mutex->wait_queue.next;
   while(curr_que != &(mutex->wait_queue))
   {
      task = get_task_in_task_queue(curr_que);
      if(task->priority < priority) //--  task priority is higher
         priority = task->priority;

      curr_que = curr_que->next;
   }

   return priority;
}

void set_current_priority(TASK * task, int priority)//??
{
   MUTEX * mutex;

   //-- transitive priority changing

   // if we have a task A that is blocked by the task B and we changed priority
   // of task A,priority of task B also have to be changed. I.e, if we have
   // the task A that is waiting for the mutex M1 and we changed priority
   // of this task, a task B that holds a mutex M1 now, also needs priority's
   // changing.  Then, if a task B now is waiting for the mutex M2, the same
   // procedure have to be applied to the task C that hold a mutex M2 now
   // and so on.


   //-- This function in ver 2.6 is more "lightweight".
   //-- The code is derived from Vyacheslav Ovsiyenko version

   for(;;)
   {
      if(task->priority <= priority)
         return;

      if(task->task_state == TSK_STATE_RUNNABLE)
      {
         change_running_task_priority(task, priority);
         return;
      }

      if(task->task_state & TSK_STATE_WAIT)
      {
         if(task->task_wait_reason == TSK_WAIT_REASON_MUTEX_I)
         {
            task->priority = priority;

            mutex = get_mutex_in_queue(task->wait_queue);
            task  = mutex->locker;

            continue;
         }
      }

      task->priority = priority;
      return;
   }
}

int change_running_task_priority(TASK * task, int new_priority)//??
{
   int old_priority;

   old_priority = task->priority;

  //-- remove curr task from any (wait/ready) queue

   queue_remove_element(&(task->task_queue));

  //-- If there are no ready tasks for the old priority
  //-- clear ready bit for old priority

   if(is_queue_empty(&(runnable_tasks_list[old_priority])))
      priority_ready_to_run_bitmap &= ~(1<<old_priority);

   task->priority = new_priority;

  //-- Add task to the end of ready queue for current priority

   queue_insert_before(&(runnable_tasks_list[new_priority]), &(task->task_queue));
   priority_ready_to_run_bitmap |= 1 << new_priority;
   find_next_task_to_run();

   return TRUE;
}

int do_unlock_mutex(MUTEX * mutex) //??
{
   QUEUE * curr_que;
   MUTEX * tmp_mutex;
   TASK * task;
   int pr;

   //-- Delete curr mutex from task's locked mutexes queue

   queue_remove_element(&(mutex->mutex_queue));
   pr = current_running_task->base_priority;

   //---- No more mutexes, locked by the our task

   if(!is_queue_empty(&(current_running_task->mutex_queue)))
   {
      curr_que = current_running_task->mutex_queue.next;
      while(curr_que != &(current_running_task->mutex_queue))
      {
         tmp_mutex = get_mutex_in_mutex_queue(curr_que);

         
            pr = find_max_blocked_priority(tmp_mutex, pr);
         
         curr_que = curr_que->next;
      }
   }

   //-- Restore original priority

   if(pr != current_running_task->priority)
      change_running_task_priority(current_running_task, pr);


   //-- Check for the task(s) that want to lock the mutex

   if(is_queue_empty(&(mutex->wait_queue)))
   {
      mutex->locker = NULL;
      return TRUE;
   }

   //--- Now lock the mutex by the first task in the mutex queue

   curr_que = queue_remove_next(&(mutex->wait_queue));
   task     = get_task_in_task_queue(curr_que);
   mutex->locker = task;

   

   task_wait_complete(task);
   queue_insert_before(&(task->mutex_queue), &(mutex->mutex_queue));

   return TRUE;
}

int sleep(unsigned long time)
{
   INTSAVE_DATA
   int return_code;

   if(time == 0)
      return  ERR_WRONG_PARAMETER;

   CHECK_NON_INT_CONTEXT

   disable_interrupt();

   if(current_running_task->wakeup_count > 0)
   {
      current_running_task->wakeup_count--;
      return_code = ERR_NO_ERROR;
   }
   else
   {
      task_curr_to_wait_action(NULL, TSK_WAIT_REASON_SLEEP, time);
      enable_interrupt();
      switch_context();
      return  ERR_NO_ERROR;
   }
	
   enable_interrupt();
   return return_code;
}





