#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s)
{
    long long N = 0;
    char *next = strtok(s, " ");
    while (next != NULL)
    {
        next = strtok(NULL, " ");
        N++;
    }
    return N;
}

int main(int argc, char **argv)
{
    char str[1000];
    fgets(str, 1000, stdin);
    str[strlen(str)-1] = '\0';
    printf("%lld\n", wcount(str));
    return 0;
}

