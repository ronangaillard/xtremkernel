# xtremkernel

Xtremkernel is a kernel for LPC17XX arm based processors. It means it will run perfectly on the original MBED : https://developer.mbed.org/platforms/mbed-LPC1768/

## Intro

Xtremkernel support tasks, timers, semaphores and mutexes. It contains a task scheduler with priorities.

It also has a basic shell that works over the serial port. It was tried with a PS2 Keyboard and a VGA graphic card, and worked as a standalone computer.

It also has support for SD cards and the FAT filesystem, using the `Petit FAT File System Module` http://elm-chan.org/fsw/ff/00index_p.html so it can read files, navigate in folders. Next step is to load binaries from the SD and execute them as tasks.

## Building

`make` will do the trick ! Toolchain is included in this repo. (Will be removed soon, only code should be in that repo)

## TODO

- Remove shell and FAT support from kernel and load them as modules (UNIX style).
- Port code to other ARM processors (should be easy as hardware specific code is well separated from kernel core code)

## Known bugs

None known yet.
