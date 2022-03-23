#include <stdio.h>

int main(int argc, char **argv)
{
    long long x, fib1 = 1, fib2 = 1;

    scanf("%lld", &x);
    while (fib2 <= x - fib1)
    {
        fib2 = fib2 + fib1;
        fib1 = fib2 - fib1;
    }
    while (fib1 >= 1)
    {
        if (x >= fib2)
        {
            printf("1");
            x = x - fib2;
        }
        else printf("0");
        fib1 = fib2 - fib1;
        fib2 = fib2 - fib1;
    }
    return 0;
}
