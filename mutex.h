#ifndef MUTEX_H
#define MUTEX_H

#include "structures.h"


int create_mutex(MUTEX * mutex);
int delete_mutex(MUTEX * mutex);

int lock_mutex(MUTEX * mutex, unsigned long timeout);
int try_lock_mutex(MUTEX * mutex);

int unlock_mutex(MUTEX * mutex);

int find_max_blocked_priority(MUTEX * mutex, int ref_priority);



















#endif
