#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    long long a = 0, b = 0;
    int len_a, len_b, el, i;
    scanf("%d", &len_a);
    for (i = 0; i < len_a; i++)
    {
        scanf("%d", &el);
        a = a + pow(2, el);
    }
    scanf("%d", &len_b);
    for (i = 0; i < len_b; i++)
    {
        scanf("%d", &el);
        b = b + pow(2, el);
    }
    for (i = 0; (a | b); i++)
    {
        if (a % 2 & b % 2) printf("%d ", i);
        a = a / 2;
        b = b / 2;
    }
    return 0;
}

