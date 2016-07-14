#ifndef TASK_H
#define TASK_H

int create_task(TASK * task,                 //The task's TASK structure
                 void (*task_function)(void *parameters),  //Pointer to the function of the task's function
                 int priority,                    //Priority of the task
                 unsigned int * task_stack_start, //Stack base address (this is the top of the stack for Cortex M3, as stack is descending)
                 int task_stack_size,             //The size of the allocated stack for this stack (in sizeof(void*) which is 4 bytes for the Cortex M3, not in size of bytes)
                 void * parameters,                    //Parameters for the task function
                 int option);                    //Options used for the cration of the task
                 
void current_task_to_wait_state(QUEUE * wait_queue,
                              int wait_reason,
                              unsigned long timeout); //Sets the task to wait 
                              
                              
void find_next_task_to_run(void);

TASK* get_task_from_timer_queue(QUEUE* queue);

TASK* get_task_in_task_queue(QUEUE* queue);

MUTEX* get_mutex_in_wait_queue(QUEUE* queue);
int sleep(unsigned long time);

void set_task_as_runnable(TASK * task);

void task_set_dormant_state(TASK* task);

void task_to_non_runnable(TASK * task);

int task_wait_complete(TASK* task);


void task_curr_to_wait_action(QUEUE * wait_que,
                              int wait_reason,
                              unsigned long timeout);//??
                              
                              void exit_task(int attribut);//??
                              
                              int find_max_blocked_priority(MUTEX * mutex, int ref_priority);//??
                              
                              void set_current_priority(TASK * task, int priority);//??
                              
                              int do_unlock_mutex(MUTEX * mutex) ;//??
                              
                              int change_running_task_priority(TASK * task, int new_priority);//??
                              
                              MUTEX* get_mutex_in_mutex_queue(QUEUE* queue);

#endif
