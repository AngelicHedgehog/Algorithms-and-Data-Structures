#include <stdio.h>
#include <string.h>

void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
        int a, b;
        if (nel > 1)
            for (a=0; a<nel-1; a++)
                if (a % 2)
                {
                    for (b=nel-2; b>1; b--)
                        if (compare(b - 1, b) == 1)
                            swap(b - 1, b);
                }
                else
                {
                    for (b=0; b<nel-1; b++)
                        if (compare(b, b + 1) == 1)
                            swap(b, b + 1);
                }
}
