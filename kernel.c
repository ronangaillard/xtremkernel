#include "constants.h"
#include "structures.h"
#include "utilities.h"
#include "kernel.h"
#include "task.h"
#include "hardware.h"

#include "uart.h"

#include "terminal.h"
#include "keyboard.h"


extern unsigned int  _HEAP_START;
extern unsigned int  _HEAP_END;

//----------------------------------------------------------------------
//Global variables for the entire kernel are declared just below :
//----------------------------------------------------------------------


volatile int num_tasks;                					    //Number of tasks

QUEUE runnable_tasks_list[NUMBER_OF_PRIORITY_LEVELS];       //(Circular) list/queue of all RUNNABLE tasks (in an array, tasks being ordered by their level of priority)
QUEUE all_tasks_queue;                       			    //(Circular) list/queue of all tasks
QUEUE waiting_timeout_tasks_list;                  			//(Circular) list/queue of tasks waiting for timmeout

unsigned short time_slice_ticks[NUM_PRIORITY];  			//Used for round-robin scheduling

volatile int system_state;                    			//State of the system (running, waiting, not running,...)

TASK * next_task_to_run;                     //Next task to be run after "context switch"
TASK * current_running_task;                        //The task that is currently running

volatile unsigned int priority_ready_to_run_bitmap; //A bitmap showing in which priority there are tasks ready to be run
volatile unsigned long idle_count;
volatile unsigned long current_performance;


//----------------------------------------------------------------------
//System tasks
//We define two tasks for the system that will always be created
//See documentation for more info
//----------------------------------------------------------------------

//Timer task (with priority 0, which is the highest priority)

unsigned int timer_task_stack[TIMER_STACK_SIZE] align_attr_end;

TASK timer_task;
static void timer_task_function(void * parameters);

//Idle task (with priority 31, which is the lowest priority, used for statisitics only)

unsigned int idle_task_stack[IDLE_STACK_SIZE] align_attr_end;

TASK  idle_task;




static void idle_task_function(void * parameters);


static void calc_performance(void);

//----------------------------------------------------------------------
//Main kernel function, this basically from where everything starts!
//----------------------------------------------------------------------

void kernel_main(void)
{

   send_data_uart0_str("Inside kernel, initialising\r\n");
   
   send_data_uart0_str("Init of Terminal \r\n");
	
	terminal_init();
	
	terminal_println("#################################################");
	terminal_println("#                                               #");
	terminal_println("#               XTrem Kernel v0.3               #");
	terminal_println("#                                               #");
	terminal_println("#           (c) Ronan Gaillard 2015             #");
	terminal_println("#                                               #");
	terminal_println("#################################################");
	
	terminal_println("");
	send_data_uart0_str("Printing! \r\n");
	
	terminal_println("Hardware init finished");
	terminal_println("Terminal has been initialized!");

	

	
	
   int i;

   //Clears all queues and sets some variables to 0
   terminal_println("Clearing all queues");
   for(i=0;i < NUM_PRIORITY;i++)
   {
      reset_queue(&(runnable_tasks_list[i]));
      time_slice_ticks[i] = NO_TIME_SLICE;
   }

   reset_queue(&all_tasks_queue);
   num_tasks = 0;

   system_state = STATE_NOT_RUNNING;

   priority_ready_to_run_bitmap = 0;

   idle_count       = 0;
   current_performance = 0;

   next_task_to_run = NULL;
   current_running_task    = NULL;

  //Initializing both main tasks declared above
	terminal_print("Initialiazing system tasks");
   reset_queue(&waiting_timeout_tasks_list);



   create_task((TASK*)&timer_task,        
                  timer_task_function,             
                  0,                              //Task priority
                  &(timer_task_stack           //Stack base addres
                      [TIMER_STACK_SIZE-1]),
                  TIMER_STACK_SIZE,            //Stack size
                  NULL,                           //Parameters
                  TASK_TIMER);                 //Creation option



   create_task((TASK*)&idle_task,        
                  idle_task_function,              
                  NUM_PRIORITY-1,              //Task priority
                  &(idle_task_stack            //Stack base address
                      [IDLE_STACK_SIZE-1]),
                  IDLE_STACK_SIZE,             //Stack size
                  NULL,                           //Parameters
                  TASK_IDLE);                  //Creation option
                  
    terminal_println(" : done");
    terminal_print("Number of task(s) created : ");
    terminal_println(itoa(num_tasks));
   

    //-- Activate timer & idle tasks

   next_task_to_run = &idle_task; //so that we have a next task to run

   set_task_as_runnable(&idle_task); //set both task to the runnable state
   set_task_as_runnable(&timer_task); 

   current_running_task = &idle_task;  //so that we have at least one running task


   
   //Inits the heap by creating the first memory chunk 
      terminal_print("Heap start address : ");
   terminal_println(itoa(_HEAP_START));
   terminal_print("Heap end address : ");
   terminal_println(itoa(_HEAP_END));
   
  /* MEMORY_CHUNK* first_mem_chunk = (MEMORY_CHUNK*)_HEAP_START;
   first_mem_chunk->size = SIZE_INFINITE;
   first_mem_chunk->status = MEMORY_STATUS_FREE;*/
   
      terminal_println("Heap NOT initialized!");

   terminal_print("Initialing keyboard");
   keyboard_init();
   terminal_println(" : done");
   
   
   //Lauches the OS and the context switch   
   terminal_println("Kernel init : done");
   terminal_println("Launching scheduler");

   launch_os(); //declared in assembly
   
   terminal_println("Oups! This code should not be executed!\r\n");
	
	
}

static void idle_task_function(void * parameters)
{
	
	send_data_uart0_str("Idle task launched\r\n");

   for(;;)
   {


      idle_count++;
	//send_data_uart0_str(".");
   }
}

static void timer_task_function(void * parameters)
{
   
   send_data_uart0_str("Timer task launched\r\n");
   INTSAVE_DATA
   
   volatile TASK * task;
   volatile QUEUE * current_queue;

   
   app_init();

   enable_interrupt();//??

  

   for(;;)
   {
	//send_data_uart0_str("|");
     //logic for timing and wziting ofr timeout taks runs here

      disable_interrupt(); //assembly function

      current_queue = waiting_timeout_tasks_list.next;
      while(current_queue != &waiting_timeout_tasks_list) //We go through the whole queue
      {
         task = get_task_from_timer_queue((QUEUE*)current_queue);
         
         if(task->tick_count != WAIT_INFINITE) //We don't take tasks waiting for an infinite amount of time into account
         {
            if(task->tick_count > 0)
            {
               task->tick_count--;
               if(task->tick_count == 0) //Time out as expired, the task is now runnable again!
               {
                  queue_remove_element(&(((TASK*)task)->task_queue));
                  task_wait_complete((TASK*)task);
                  task->task_wait_return_code = ERR_TIMEOUT; //Actually not really an error, but infrmation to know what happened
               }
            }
         }

         current_queue = current_queue->next;
      }

      task_curr_to_wait_action(NULL,
                               TSK_WAIT_REASON_SLEEP,
                               WAIT_INFINITE);
      enable_interrupt();

      switch_context();
   }
}


/*void PendSV_Handler(void)
{
	send_data_uart0_str("In PendSv Handler");
	
	//int_exit();
}*/
void SysTick_Handler(void)
{
	
	//send_data_uart0_str("%");
   tick_int_processing();

   calc_performance();

 
  
  
//send_data_uart0_str("Leaving SysTick Handler!\r\n");
   int_exit(); //-- !!!    For the Cortex CPU, this function always MUST be a last func in 
  //--     any user's interrupt handler  
}

//----------------------------------------------------------------------------
void  tick_int_processing(void)
{
   INTSAVE_DATA_INT

   volatile QUEUE * curr_que;   
   volatile QUEUE * pri_queue;  
   volatile int priority;

   CHECK_INT_CONTEXT_NORETVAL

   idisable_interrupt();

//-------  Round -robin

   priority  = current_running_task->priority;

   if(time_slice_ticks[priority] != NO_TIME_SLICE)
   {
      current_running_task->time_slice_count++;
      if(current_running_task->time_slice_count > time_slice_ticks[priority])
      {
         current_running_task->time_slice_count = 0;

         pri_queue = &(runnable_tasks_list[priority]);
        //-- If ready queue is not empty and qty  of queue's tasks > 1
         if(!(is_queue_empty((QUEUE *)pri_queue)) && pri_queue->next->next != pri_queue)
         {
 

           //-- Remove task from head and add it to the tail of
           //-- ready queue for current priority

            curr_que = queue_remove_next(&(runnable_tasks_list[priority]));
            queue_insert_before(&(runnable_tasks_list[priority]),(QUEUE *)curr_que);
         }
      }
   }

  //Enable a task with priority 0 - timer_task

   queue_remove_element(&(timer_task.task_queue));
   timer_task.task_wait_reason = 0;
   timer_task.task_state       = TSK_STATE_RUNNABLE;
   timer_task.wait_queue      = NULL;
   timer_task.task_wait_return_code     = ERR_NO_ERROR;

   queue_insert_before(&(runnable_tasks_list[0]), &(timer_task.task_queue));
   priority_ready_to_run_bitmap |= 1;  // priority 0;

   next_task_to_run = &timer_task;

   ienable_interrupt();  
}

static void calc_performance(void)
{
   static int cnt = 0;

   cnt++;
   if(cnt == 1000)  //-- 1 s
   {
      cnt = 0;

      current_performance = idle_count;
      idle_count = 0;

   
   }
}

void UART0_IRQHandler(void)
{
	int_exit();
}




