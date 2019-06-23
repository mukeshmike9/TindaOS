    OBJECTS = loader.o kmain.o
    CC = gcc
    CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
             -nostartfiles -nodefaultlibs -fno-pic -Wall -Wextra -Werror -c
    LDFLAGS = -T link.ld -melf_i386
    AS = nasm
    ASFLAGS = -f elf

    all: tindaos.elf

    tindaos.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o tindaos.elf

    tindaos.iso: tindaos.elf
	cp tindaos.elf iso/boot/tindaos.elf
	genisoimage -R                              \
                    -b boot/grub/stage2_eltorito    \
                    -no-emul-boot                   \
                    -boot-load-size 4               \
                    -A os                           \
                    -input-charset utf8             \
                    -quiet                          \
                    -boot-info-table                \
                    -o tindaos.iso                       \
                    iso

    run: tindaos.iso
	bochs -f bochsrc.bxrc -q

    %.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

    %.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

    clean:
	rm -rf *.o tindaos.elf tindaos.iso
	rm -rf iso/boot/tindaos.elf
