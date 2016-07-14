#ifndef KERNEL_H
#define KERNEL_H

#include "constants.h"
#include "structures.h"
#include "types.h"

#define USE_MUTEXES
#define USE_EVENTS
void kernel_main(void);

void  tick_int_processing(void);

//assembly

void launch_os(void);
void switch_context(void);
int cpu_save_sr(void);
void cpu_restore_sr(int);
void switch_context_exit(void);
void int_exit(void);


//external
void app_init(void);


#endif
