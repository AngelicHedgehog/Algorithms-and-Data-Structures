#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void revarray(void *base, size_t nel, size_t width)
{
    for (int i = 0; i<nel/2; i++)
    {
        char *arr = (char*)base;
        int j = nel - i - 1, w = width;
        char *l = arr + i * w,
             *r = arr + j * w,
             *h = malloc(w);
        memcpy(h, r, w);
        memcpy(r, l, w);
        memcpy(l, h, w);
        free(h);
    }
}
