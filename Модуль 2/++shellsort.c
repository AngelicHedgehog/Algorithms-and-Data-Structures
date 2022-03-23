#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    int fib1 = 1, fib2 = 2, i, j;
    while (fib2 < nel)
    {
        fib2 = fib2 + fib1;
        fib1 = fib2 - fib1;
    }
    while (fib2 > 1)
    {
        for (i=fib1; i<nel; i++)
            for (j=i; j>=fib1 && compare(j - fib1, j) == 1; j-=fib1)
                swap(j - fib1, j);
        fib1 = fib2 - fib1;
        fib2 = fib2 - fib1;
    }

}
