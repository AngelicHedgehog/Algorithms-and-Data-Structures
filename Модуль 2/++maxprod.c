#include <stdio.h>

int main(int argc, char **argv)
{
    long long n, i, j, max_i = 0, max_j = 0;
    scanf("%lld", &n);
    long long a[n], b[n];
    for (i=0; i<n; i++) scanf("%lld/%lld", &a[i], &b[i]);
    long double AB, max_ab = a[0] / b[0];

    for (i=0; i<n; i++)
    {
        AB = 1;
        for (j=i; j<n; j++)
        {
            if (!a[j] || !b[j]) break;
            AB *= a[j]; AB /= b[j];
            if (AB > max_ab)
                {max_i = i; max_j = j; max_ab = AB;}
        }
    }
    printf("%lld %lld\n", max_i, max_j);
    return 0;
}

