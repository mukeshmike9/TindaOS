#Automate this in future for different architectures
ARCH=i386

AS = nasm
ASFLAGS = -f elf
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -fno-pic -Wall -Wextra -Werror -c


ARCHDIR=./arch/$(ARCH)
KERNELDIR=./kernel

DESTDIR=./../iso
TEMPDIR=./../iso

ARCH_OBJS=\
$(ARCHDIR)/loader.o

KERNEL_OBJS=\
$(KERNELDIR)/kmain.o


all: $(ARCH_OBJS) $(KERNEL_OBJS)
	cp $(ARCHDIR)/link.ld $(TEMPDIR)

	
# Compiling arch folder 
$(ARCHDIR)/%.o: $(ARCHDIR)/%.s
	$(AS) $(ASFLAGS) $< -o $@
	mv -f $(ARCHDIR)/*.o $(TEMPDIR)/

#Compiling kernel folder
$(KERNELDIR)/%.o: $(KERNELDIR)/%.c
	$(CC) $(CFLAGS)  $< -o $@
	mv -f $(KERNELDIR)/*.o $(TEMPDIR)/


clean:
	rm -rf $(ARCHDIR)/*.o
	rm -rf $(KERNELDIR)/*.o
	rm -rf $(TEMPDIR)/*.o
	rm -rf $(TEMPDIR)/link.ld

	

