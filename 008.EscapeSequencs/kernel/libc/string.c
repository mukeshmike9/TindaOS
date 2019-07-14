#include "include/string.h"

void *memcpy(void *restrict s1,
             const void *restrict s2,
             size_t n)
{
    for (register size_t i = 0; i < n; i++)
    {
        *((char *)s1 + i) = *(char *)(s2 + i);
    }
    return s1;
}

void *memset(void *s,
             int c,
             size_t n)
{
    for (register size_t i = 0; i < n; i++)
    {
        *((char *)s + i) = c;
    }
    return s;
}
