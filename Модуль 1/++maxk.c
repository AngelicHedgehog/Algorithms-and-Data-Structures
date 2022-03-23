#include <stdio.h>

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    int i, a[n], k, sum = 0;
    for (i = 0; (i < n); i++) scanf("%d", &a[i]);
    scanf("%d", &k);

    for (i = 0; (i < k); i++) sum = sum + a[i];
    int max = sum;
    for (i = 0; (i < n - k); i++)
    {
        sum = sum + a[i + k] - a[i];
        if (max < sum) max = sum;
    };
    printf("%d", max);
    return 0;
}

