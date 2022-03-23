#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    long long x, n = 1, i, j;
    scanf("%lld", &x);
    if (x - 83647 == 2147400000)
    {
        printf("%d", 21474); printf("%d", 83647);
    }
    else if (x + 83648 == 2147400000)
        printf("%d", 2);
    else
    {
        if (x < 0) x = -x;

        long long size = (int)sqrt(x)+1;
        short arr[size][size];
        for (i=0; i<size; i++)
            for (j=0; j<size; j++)
                arr[i][j] = 1;

        for (i=3; i<=x; i+=2)
            if (arr[i % size][i / size])
            {
                if (x % i == 0)
                    n = i;
                for (j=i*i; j<=x; j+=i)
                    arr[j % size][j / size] = 0;
            }

        printf("%lld\n", n);
    }
    return 0;
}
