#@andrew
CC=arm-none-eabi-
cFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
all:	learn-in-depth.bin 
	@echo	"build done"
startup.o:	startup.s
	$(CC)as.exe $(cFLAGS)  $< -o $@
%.o:	%.c
	$(CC)gcc.exe $(cFLAGS) -c  $(INCS) $< -o $@
learn-in-depth.elf:	$(OBJ) $(ASOBJ)	
	$(CC)ld.exe -T linker_script.ld -Map=output.map $(OBJ) $(ASOBJ) -o $@
learn-in-depth.bin:	learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@
clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin
   
