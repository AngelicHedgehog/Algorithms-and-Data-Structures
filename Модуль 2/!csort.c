#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void csort(char *src, char *dest)
{
    int len = strlen(src)+1, i;
    char *next, rez[len][1000], sep[] = " ";
    for (i=0; i<len; i++) strcpy(rez[i], "");

    next = strtok(src, sep);
    while (next != NULL)
    {
        i = strlen(next);
        if (rez[i][0])
            strcat(rez[i], sep);
        strcat(rez[i], next);
        next = strtok(NULL, sep);
    }

    for (i=1; i<len; i++)
        if (rez[i][0])
        {
            if (dest[0])
                strcat(dest, " ");
            strcat(dest, rez[i]);
        }
}

int main(int argc, char **argv)
{
    char foo[1000], b[1000] = "";
    fgets(foo, 1000, stdin);
    foo[strlen(foo)-1] = '\0';
    csort(foo, b);
    printf("%s\n", b);
    return 0;
}
