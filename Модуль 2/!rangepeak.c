#include <stdio.h>

int main(int argc, char **argv)
{
    char form[5];
    long long n, m, a, b, N;
    scanf("%lld", &n);

    long long arr[n], i, j;
    for (i=0; i<n; i++) scanf("%lld", &arr[i]);

    scanf("%lld", &m);

    for (; m; m--)
    {
        scanf("%s %lld %lld", form, &a, &b);
        if (form[0] == 'U')
            arr[a] = b;
        else
        {
            N = 0;
            for (i=a; i<=b; i++)
            {
                if ((i < 1 || arr[i - 1] <= arr[i]) &&
                    (i > n-2 || arr[i + 1] <= arr[i]))
                    N++;
            }

            printf("%lld\n", N);
        }
    }

    return 0;
}
