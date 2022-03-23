#include <stdio.h>

int main(int argc, char **argv)
{
    char form[4];
    long long n, m, i, j, a, b, max;
    scanf("%lld", &n);

    long long arr[n];
    for (i=0; i<n; i++) scanf("%lld", &arr[i]);

    scanf("%lld", &m);
    for (; m; m--)
    {
        scanf("%s %lld %lld", &form, &a, &b);
        if (form[0] == 'U')
            arr[a] = b;
        else
        {
            max = arr[a];
            for (i=a+1; i<=b; i++)
                if (arr[i] > max)
                    max = arr[i];
            printf("%lld\n", max);
        }
    }

    return 0;
}
