#include <stdio.h>

int main(int argc, char **argv)
{
    int n, i, j, h;
    scanf("%d", &n);

    long long a[n], rez = 0, k;
    for (i = 0; i<n; i++) scanf("%lld", &a[i]);

    int b[n+1];
    b[0] = 1;
    for (i=1; i<=n; i++) b[i] = 0;
    while (b[n] == 0)
    {
        k = 0;
        for (i=0; i<n; i++)
            k += a[i] * b[i];
        if (k > 0)
        {
            rez += 1;
            for (i=k; k>1; k/=2)
                if (k % 2)
                {
                    rez -= 1;
                    break;
                }
        }

        b[0] += 1;
        for (i=0; i<n; i++)
            if (b[i] == 2)
            {
                b[i] = 0;
                b[i + 1] += 1;
            }
    }

    printf("%lld\n", rez);

    return 0;
}
