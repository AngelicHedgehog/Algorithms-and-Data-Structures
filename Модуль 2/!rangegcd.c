#include <stdio.h>

int main(int argc, char **argv)
{
    long long n, m, i, j, l, r, gcd, g, f;
    scanf("%lld", &n);

    long long a[n];
    for (i=0; i<n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] < 0) a[i] = -a[i];
    }

    scanf("%lld", &m);
    for (; m; m--)
    {
        scanf("%lld %lld", &l, &r);

        gcd = a[l];
        for (i=l+1; i<=r; i++)
        {
            g = a[i];
            while (g)
            {
                f = gcd % g;
                gcd = g;
                g = f;
            }
        }
        printf("%lld\n", gcd);
    }
    return 0;
}
