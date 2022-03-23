#include <stdio.h>

int main(int argc, char **argv)
{
    long long n, x, a, F = 0, f = 0;

    scanf("%lld%lld", &n, &x);

    int i;
    for (i = 0; i<=n; i++)
    {
        scanf("%lld", &a);
        F = F * x + a;
        if (i<n) f = f * x + a * (n-i);
    }

    printf("%lld %lld", F, f);
    return 0;
}
