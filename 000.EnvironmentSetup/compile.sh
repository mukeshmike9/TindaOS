#! /bin/bash

nasm -f elf32 -o loader.o loader.s

ld -T link.ld -melf_i386 loader.o -o tindaOs.elf 

cp tindaOs.elf iso/boot/
