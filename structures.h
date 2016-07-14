#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct QUEUE //Simple linked queue with previous and next elements, should be circular
{
   struct QUEUE * previous;
   struct QUEUE * next;
}QUEUE;



//FIFO

typedef struct FIFO
{
   QUEUE  wait_send_list;
   QUEUE  wait_receive_list;

   void ** data_fifo;    //Array of elements (of whatever type)
   int  size;    //Number of elements
   int  index_of_next_inserted_element;       
   int  index_of_next_read_element;    		
   int  fifo_type;        //Type of the FIFO or of data type contianed in the fifo
}FIFO;



//TASK, contains all needed info on a task

typedef struct TASK
{
   unsigned int * task_stack;   //Pointer to the bottom of the stack (where the current last value is) (remember on Cortex M3 stack is descending)
   
   QUEUE task_queue;     //Used to include task in ready/wait lists
   QUEUE timer_queue;    //Used to include task in timer(timeout,etc.) list
   QUEUE * wait_queue;   //Pointer to object's(semaphor,event,etc.) wait list                                 
   QUEUE temp_queue;   	 //Temporary queue used to insert this task in other queues
   QUEUE mutex_queue;    //List of all mutexes this task locked


   unsigned int * stack_start;  //Base address of stack allocated for this task
   int   stack_size;            //The size of the allocated stack for this stack (in sizeof(void*) which is 4 bytes for the Cortex M3, not in size of bytes)
   void * task_function_address;       //address of function which contains task's code
   void * task_function_parameters;    //pointer to parameters

   int  base_priority;        //Task's base priority
   int  priority;             //Task's current priority
  

   int  task_state;           //The state of the task (running, not running,...)
   int  task_wait_reason;     //Why the task is waiting?
   int  task_wait_return_code;         //Reason why waiting finished
   unsigned long tick_count;  //The time remaining before timeout is finished
   int  time_slice_count;         //Time slice counter


   int  event_wait_pattern;        //Event wait pattern; more info in events method or in documentation
   int  event_wait_mode;           //Event wait mode:  _AND or _OR


   void * data_element;          //A data element, needed to store temporally if queue is full

   int  activate_count;       //Activation request count -used for statistics only
   int  wakeup_count;         //Wakeup request count -used for statistics only
   int  suspend_count;        //Suspension count -used for statistics only


}TASK;


//Mutexes
typedef struct MUTEX
{
   QUEUE wait_queue;        //A list of tasks which wait for the mutex
   QUEUE mutex_queue;       //Task's locked mutexes?
   QUEUE lock_mutex_queue;  //To include in system's locked mutexes list ??

   TASK * locker;              //The task that is currently locking the mutex
   int ceil_priority;            //When mutex created with CEILING attr??
   int counter;                      //??
   
}MUTEX;

typedef struct SEMAPHORE
{
   QUEUE  wait_queue;
   int count;
   int max_count;
   
}SEMAPHORE;

typedef struct EVENT
{
   QUEUE wait_queue;
   int attribute;               //-- Eventflag attribute
   unsigned int pattern;   //-- Initial value of the eventflag bit pattern
   
}EVENT;

typedef struct MEMORY_CHUNK
{
   int status;
   int size;
   // *
   // *
   // DATA
   // *
   // *
   
 
}MEMORY_CHUNK;

#endif
