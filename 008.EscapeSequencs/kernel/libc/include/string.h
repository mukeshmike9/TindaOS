#ifndef _STRING_H
#define _STRING_H

#include "types.h"

void *memcpy(void *s1,
             const void *s2,
             size_t n);

void *memset(void *s,
             int c,
             size_t n);

#endif