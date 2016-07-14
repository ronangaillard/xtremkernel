#include "memory.h"
#include "kernel.h"
#include "types.h"
#include "constants.h"
#include "structures.h"


extern unsigned int  _HEAP_START;

void* x_malloc(unsigned int size)
{
	MEMORY_CHUNK* current_mem_chunk = (MEMORY_CHUNK*)_HEAP_START; //first memory chunk
	
	while(current_mem_chunk->status != MEMORY_STATUS_FREE && current_mem_chunk->size >= size)
	{
		current_mem_chunk = (MEMORY_CHUNK*)(sizeof(MEMORY_CHUNK) + current_mem_chunk->size);
	}
	
	
	
	//We prepare the next memory check which is a the end of the current one :
	
	
	
	if(current_mem_chunk->size != SIZE_INFINITE && size >= current_mem_chunk->size - sizeof(MEMORY_CHUNK))//We don't have enough space to introduce a memory chunk between the next chunk and the chunk we are created, so we expand the chunk we are creating so that it fits all the space
	{
		//so the mem chunk already exists and is already at the good size, we just need to set it to "allocated"
		
		current_mem_chunk->status = MEMORY_STATUS_ALLOCATED;
		return (void*)(current_mem_chunk + sizeof(MEMORY_CHUNK));
	}
	else
	{
		MEMORY_CHUNK* next_mem_chunk = NULL;
		next_mem_chunk = (MEMORY_CHUNK*)((int)current_mem_chunk + sizeof(MEMORY_CHUNK) + size);
		
		next_mem_chunk->status = MEMORY_STATUS_FREE;
		if(current_mem_chunk->size == SIZE_INFINITE)
			next_mem_chunk->size = SIZE_INFINITE;
		else
			next_mem_chunk->size = current_mem_chunk->size - size - sizeof(MEMORY_CHUNK);
		
		current_mem_chunk->size = size;
		current_mem_chunk->status = MEMORY_STATUS_ALLOCATED;
		
		return (void*)(current_mem_chunk + sizeof(MEMORY_CHUNK));
	}
	
	
	
	current_mem_chunk->size = size;
	current_mem_chunk->status = MEMORY_STATUS_ALLOCATED;

	return (void*)(current_mem_chunk + sizeof(MEMORY_CHUNK));	//The data starts just after the memory chunk information
}



void free(void* pointer)
{
	
}
