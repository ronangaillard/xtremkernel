#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "structure.h"

int create_semaphore(SEMAPHORE * sem, int start_value, int max_value);
int delete_semaphore(SEMAPHORE * sem);

int semaphore_signal(SEMAPHORE * sem);

int release_semaphore_i(SEMAPHORE * sem);

int acquire_semaphore(SEMAPHORE * sem, unsigned long timeout);
int acquire_semaphore_polling(SEMAPHORE * sem);
int acquire_semaphore_polling_i(SEMAPHORE * sem);
#endif
