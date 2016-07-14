#ifndef UTILITIES_H
#define UTILITIES_H

#include "structures.h"
#include "types.h"


//#define align_attr_end	__attribute__((aligned(0x8)))

//----------------------------------------------------------------------
//Utilities concerning QUEUES
//----------------------------------------------------------------------

void reset_queue(QUEUE* qu);
BOOL is_queue_empty(QUEUE* qu);
void queue_insert_after(QUEUE* qu, QUEUE* element);
void queue_insert_before(QUEUE* qu, QUEUE* element);
QUEUE* queue_remove_next(QUEUE * qu);
QUEUE* queue_remove_previous(QUEUE * qu);
void queue_remove_element(QUEUE* element);
BOOL queue_contains_element(QUEUE* qu, QUEUE * element);

//----------------------------------------------------------------------
//Utilities concerning FIFOs
//----------------------------------------------------------------------

int  fifo_add(FIFO * fif, void * data);
int  fifo_read(FIFO * fif, void ** data);

//----------------------------------------------------------------------
//Utilities concerning Bytes and bits manipulation

char high_byte(unsigned int i);
char low_byte(unsigned int i);





int x_strcmp(const char *s1, const char *s2);



                


#endif

char* itoa(int i);
