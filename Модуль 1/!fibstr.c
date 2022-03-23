#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *a, *b, *c;

char *fibstr(int n)
{
    strcpy(a, "a"); strcpy(b, "b");
    n--;
    for (; n; n--)
    {
        strcpy(c, b);
        strcat(a, b);
        strcpy(b, a);
        strcpy(a, c);
    }
    return a;
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);

    int fib1=1, fib2=1;
    for (int i=0; i<n; i++)
    {
        fib2 = fib2 + fib1;
        fib1 = fib2 - fib1;
    }
    a = malloc(sizeof(char) * fib1);
    b = malloc(sizeof(char) * fib2);
    c = malloc(sizeof(char) * fib2);

    printf("%s\n", fibstr(n));
    free(a); free(b); free(c);
    return 0;
}
