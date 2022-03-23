#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxarray(void *base, size_t nel, size_t width,
        int (*compare)(void *a, void *b))
{
    int rez_i = 0;
    char *based = (char*)base,
         *rez = malloc(width);
    memcpy(rez, based, width);
    for (int i = 1; i<nel; i++){
        char *elm = based + i * width;
        if (compare(rez, elm) < 0){
            rez_i = i;
            memcpy(rez, elm, width);
        }
    }
    free(rez);
    return rez_i;
}
