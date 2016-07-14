#include "kernel.h"
#include "utilities.h"
#include "structures.h"
#include "types.h"
#include "constants.h"


//----------------------------------------------------------------------
//Utilities concerning QUEUES
//----------------------------------------------------------------------

void reset_queue(QUEUE* qu)
{
	qu->previous = qu;
	qu->next = qu;
}

BOOL is_queue_empty(QUEUE* qu)
{
	if(qu->next == qu && qu->previous == qu)
      return TRUE;
   return FALSE;
}

void queue_insert_after(QUEUE* qu, QUEUE* element)
{
  //Inserts an element in the queue (after qu)
  
  //-----------------------------------
  //  -  | qu  |  -  | ...
  //-----------------------------------
  
  //-----------------------------------
  //  -  | qu  |element|  -  | ...
  //-----------------------------------

   element->next = qu->next;
   element->previous = qu;
   element->next->previous = element;
   qu->next = element;
}

void queue_insert_before(QUEUE* qu, QUEUE* element)
{
  //Inserts an element in the queue (before qu)
  
  //-----------------------------------
  //... |  -  |  -  | qu  |  -  | ...
  //-----------------------------------
  
  //-----------------------------------
  //... |  -  |element| qu  |  -  | ...
  //-----------------------------------
  
   element->next = qu;
   element->previous = qu->previous;
   element->previous->next = element;
   qu->previous = element;
}

QUEUE* queue_remove_next(QUEUE * qu)
{
   //Removes next element of queue and returns the element removed

   QUEUE * removed;

   if(qu == NULL || qu->next == qu)
      return (QUEUE *) 0;

   removed = qu->next;
   removed->next->previous = qu;
   qu->next = removed->next;
   
   return removed;
}

QUEUE* queue_remove_previous(QUEUE * qu)
{
   //Removes previous element and returns the element removed

   QUEUE * removed;

   if(qu->previous == qu)
      return (QUEUE *) 0;

   removed = qu->previous;
   removed->previous->next = qu;
   qu->previous = removed->previous;
   
   return removed;
}

void queue_remove_element(QUEUE* element)
{
   //Removes the element from the queue

   element->previous->next = element->next;
   element->next->previous = element->previous;
}

BOOL queue_contains_element(QUEUE* qu, QUEUE * element)
{
  //Checks if the queue contains the element
  //BE CAREFUL, queue should be circular!

   QUEUE * current_qu;

   current_qu = qu->next;
   while(current_qu != qu)
   {
      if(current_qu == element)
         return TRUE;   //Queue contains element

      current_qu = current_qu->next;
   }

   return FALSE; //Queue does not contain element
}
	
	
//----------------------------------------------------------------------
//Utilities concerning FIFOs
//Most of this code comes from ideas studied at Supelec Rennes in 2014/2015
//----------------------------------------------------------------------


int  fifo_add(FIFO * fif, void * data)
{
	//Adds an element in the fifo and returns an error code (ERR_NO_ERROR if no error)

   if(fif->size <= 0)
      return ERR_OUT_OF_MEMORY;

   
   if((fif->index_of_next_read_element == 0 && fif->index_of_next_inserted_element == fif->size- 1) || fif->index_of_next_inserted_element == fif->index_of_next_read_element-1)
      return  ERR_OVERFLOW;  //FIFO is full

   //Let's write the data

   fif->data_fifo[fif->index_of_next_inserted_element] = data;
   fif->index_of_next_inserted_element++;
   if(fif->index_of_next_inserted_element >= fif->size)
      fif->index_of_next_inserted_element = 0;
   return ERR_NO_ERROR;
}

int  fifo_read(FIFO * fif, void ** data)
{

	//Reads one data from FIFO and put the data in the data pointer. Returns an error code (ERR_NO_ERROR if no error)
   if(fif == NULL || data == NULL)
      return ERR_WRONG_PARAMETER;



   if(fif->size <= 0)
      return ERR_OUT_OF_MEMORY;

   if(fif->index_of_next_read_element == fif->index_of_next_inserted_element)
      return ERR_UNDERFLOW; //It means that FIFO is empty

   //Let's read the data

   *data  =  fif->data_fifo[fif->index_of_next_read_element];
   fif->index_of_next_read_element++;
   if(fif->index_of_next_read_element >= fif->size)
      fif->index_of_next_read_element = 0;

   return ERR_NO_ERROR;
}

#define INT_DIGITS 19		/* enough for 64 bit integer */

char* itoa(int i)
{
  /* Room for INT_DIGITS digits, - and '\0' */
  static char buf[INT_DIGITS + 2];
  char *p = buf + INT_DIGITS + 1;	/* points to terminating '\0' */
  if (i >= 0) {
    do {
      *--p = '0' + (i % 10);
      i /= 10;
    } while (i != 0);
    return p;
  }
  else {			/* i < 0 */
    do {
      *--p = '0' - (i % 10);
      i /= 10;
    } while (i != 0);
    *--p = '-';
  }
  return p;
}


char high_byte(unsigned int i)
{
	return (i >> 8) & 0xFF; 
}
char low_byte(unsigned int i)
{
	return i & 0xFF;
}

int x_strcmp(const char *s1, const char *s2)

{
  int ret = 0;

  while (!(ret = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2) ++s1, ++s2;

  if (ret < 0)

    ret = -1;
  else if (ret > 0)

    ret = 1 ;

  return ret;
}
