#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
    char a[1000000]; gets(a);

    int b[28] = {0};
    for (int i=0; a[i]; i++)
        b[(int)a[i] - 97]++;

    for (int i=0; i<28; i++)
        for (; b[i]; b[i]--)
            printf("%c", i + 97);

    printf("\n");
    return 0;
}
