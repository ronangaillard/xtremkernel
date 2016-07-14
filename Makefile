FORMAT = ihex


TOOLSROOT = c:\"Program Files (x86)"\"GNU Tools ARM Embedded"\"4.9 2015q2"
TOOLS     = $(TOOLSROOT)/bin/arm-none-eabi-

PRJROOTPATH   = D:/Documents/RonanKernel/kernel
PRJPATH       = D:/Documents/RonanKernel/kernel


OBJ_DIR       = $(PRJPATH)/output/OBJ
LSTPATH       = $(PRJPATH)/output/LST

CPUPATH         = $(PRJROOTPATH)/cpu
FATPATH         = $(PRJROOTPATH)/fat
ASSEMBLYFILE    = $(PRJROOTPATH)/assembly
COMMONPATH   = $(PRJROOTPATH)/common


INCLUDES = -I ./ -I $(PRJROOTPATH) -I ./terminal -I ./fat

VPATH = $(PRJPATH) $(CPUPATH) $(COMMONPATH) $(ASSEMBLYFILE) $(FATPATH)

OBJCOPY = $(GCC_BIN)arm-none-eabi-objcopy

IMAGE = kernel

LDSCRIPT = $(CPUPATH)/LPC1766_gcc.ld

OBJECTS = \
  $(OBJ_DIR)/LPC17XX_Startup.o\
  $(OBJ_DIR)/startup_hardware_init.o\
  $(OBJ_DIR)/launch_os.o\
  $(OBJ_DIR)/kernel.o\
  $(OBJ_DIR)/hardware.o\
  $(OBJ_DIR)/uart.o\
  $(OBJ_DIR)/task.o\
  $(OBJ_DIR)/utilities.o\
  $(OBJ_DIR)/main.o\
  $(OBJ_DIR)/lpc17xx_core.o\
  $(OBJ_DIR)/memory.o\
  $(OBJ_DIR)/sd.o\
  $(OBJ_DIR)/terminal.o\
  $(OBJ_DIR)/keyboard.o\
  $(OBJ_DIR)/diskio.o\
  $(OBJ_DIR)/pff.o\
  $(OBJ_DIR)/spi.o
 #$(OBJ_DIR)/mutex.o\
 #$(OBJ_DIR)/semaphore.o\


DEP_FILE =  $(OBJ_DIR)/$(notdir $(basename $@).d)


CC      = $(TOOLS)gcc.exe
AS      = $(TOOLS)as.exe
CPP     = $(TOOLS)g++.exe
LD      = $(TOOLS)ld.exe
OBJCOPY = $(TOOLS)objcopy.exe
OBJDUMP = $(TOOLS)objdump.exe
SIZE    = $(TOOLS)size.exe
NM      = $(TOOLS)nm.exe
REMOVE  = rm
COPY    = copy

ASMOPTS = -mcpu=cortex-m3 -mthumb --gdwarf-2 -mthumb-interwork
ASMLST = -alhms=$(LSTPATH)/$(notdir $(basename $@).lst)

CCOPTS  = $(INCLUDES) $(CDEF) -c -mcpu=cortex-m3 -mthumb -gdwarf-2 \
    -Wall -O1 -mapcs-frame -mthumb-interwork -mlittle-endian \
    -Wnested-externs -Wpointer-arith -Wswitch -fno-builtin\
    -Wredundant-decls -Wreturn-type -Wshadow -Wstrict-prototypes -Wunused

LDFLAGS = -T$(LDSCRIPT) -mcpu=cortex-m3 -mthumb -mthumb-interwork \
          -Wl,-Map=$(OBJ_DIR)/$(IMAGE).map -nostartfiles




$(OBJ_DIR)/%.o: %.s
	$(AS) $(ASMOPTS) $< $(ASMLST) -o $@
	
$(OBJ_DIR)/%.o:  %.c 
	$(CC) $(CCOPTS) $< -MD -MF $(DEP_FILE) -o $@

include  $(wildcard   $(OBJ_DIR)/$(notdir $(basename *.*).d))



all: $(PRJPATH)/output/$(IMAGE).elf

$(PRJPATH)/output/$(IMAGE).elf: $(OBJECTS)

	$(CC) $(OBJECTS) $(LDFLAGS) --output $(OBJ_DIR)/$(notdir $@)
	$(OBJCOPY) -O$(FORMAT)    $(OBJ_DIR)/$(IMAGE).elf  $(OBJ_DIR)/$(IMAGE).hex

	$(SIZE) -A $(OBJ_DIR)/$(IMAGE).elf
	
	
#Generate bin file and copy it to mbed
	
	$(OBJCOPY) -O binary $(OBJ_DIR)/$(IMAGE).elf F:/$(IMAGE).bin

#Clean
.PHONY:   clean

clean:

	$(REMOVE) -f $(LSTPATH)/*.lst 
	$(REMOVE) -f $(OBJ_DIR)/*.*



