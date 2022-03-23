#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    long long x, y, m, xy;
    scanf("%lld%lld%lld", &x, &y, &m);
    x %= m; y %= m;

    int a[63], b[63], c[63], ab[126] = {0}, i, j, ab_i, c_i;
    for (i=0; i<63; i++)
    {
        a[i] = x % 2; x /= 2;
        b[i] = y % 2; y /= 2;
        c[i] = m % 2; m /= 2;
    }
    for (i=0; i<63; i++)
        for (j=0; j<63; j++)
            ab[i + j] += a[i] * b[j];
    for (i=0; i<126; i++)
    {
        while (ab[i] > 1)
        {
            ab[i + 1] += 1;
            ab[i] -= 2;
        }
        if (ab[i]) ab_i = i;
        if (i<63 & c[i]) c_i = i;
    }
    for (j=ab_i-c_i-1; ab_i>=63; j=ab_i-c_i-1)
    {
        for (i=0; i<63; i++)
            ab[i + j] -= c[i];
        for (i=0; i<126; i++)
        {
            while (ab[i] < 0)
            {
                ab[i + 1] -= 1;
                ab[i] += 2;
            }
            if (ab[i]) ab_i = i;
        }
    }

    xy = 0; m = 0;
    for (i=62; i>=0; i--)
    {
        xy = xy * 2 + ab[i];
        m = m * 2 + c[i];
    }
    printf("%lld\n", xy % m);
    return 0;
}
