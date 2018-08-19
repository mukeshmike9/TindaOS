rm -rf boot_sec_print.bin
nasm -f bin boot_sec_print.asm -o boot_sec_print.bin

qemu-system-x86_64 boot_sec_print.bin
