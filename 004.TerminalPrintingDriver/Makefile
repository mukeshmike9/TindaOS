ROOT=./iso

DESTDIR=$(ROOT)


LDFLAGS = -T $(DESTDIR)/link.ld -melf_i386


OBJECTS=$(DESTDIR)/*.o 

all: compile tindaos.elf
	echo "ELF File Generated"

compile:
	$(MAKE) -C ./kernel/
		
$(OBJECTS): compile

tindaos.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o $(DESTDIR)/tindaos.elf

run: tindaos.iso
	bochs -f .bochsrc.bxrc -q

tindaos.iso: tindaos.elf
	cp $(DESTDIR)/tindaos.elf $(ROOT)/boot/tindaos.elf
	genisoimage -R                              \
                    -b boot/grub/stage2_eltorito    \
                    -no-emul-boot                   \
                    -boot-load-size 4               \
                    -A os                           \
                    -input-charset utf8             \
                    -quiet                          \
                    -boot-info-table                \
                    -o $(DESTDIR)/tindaos.iso                       \
                    iso



clean:
	$(MAKE) clean -C ./kernel/
	rm -rf $(DESTDIR)/tindaos.elf
	rm -rf $(DESTDIR)/bochslog.txt
	rm -rf $(DESTDIR)/tindaos.iso
	rm -rf $(ROOT)/boot/tindaos.elf
