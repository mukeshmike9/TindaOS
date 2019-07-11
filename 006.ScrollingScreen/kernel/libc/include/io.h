#ifndef _IO_H
#define _IO_H
#include "types.h"

/**
 * Sends a 8/16/32-bit value on a I/O location. 
 * Traditional names are outb, outw and outl respectively. 
 * The a modifier enforces val to be placed in the eax register before the asm command is issued 
 * and Nd allows for one-byte constant values to be assembled as constants, 
 * freeing the edx register for other cases.
 * @param port : Port Number
 * @param val : Byte Value to be put on port
 */
static inline void outb(uint16_t port, uint8_t val)
{
    asm volatile("outb %0, %1" ::"a"(val), "Nd"(port));
}

/**
 * Receives a 8/16/32-bit value from an I/O location. 
 * Traditional names are inb, inw and inl respectively.
 */
static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile("inb %1, %0"
                 : "=a"(ret)
                 : "Nd"(port));
    return ret;
}
#endif