#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    int n, i, j, t, f;
    scanf("%d ", &n);
    char a[n][1000];
    for (i=0; i<n; i++)
    {
        fgets(a[i], 1000, stdin);
        a[i][strlen(a[i])-1] = '\0';
    }
    int dat[n][n];
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            dat[i][j] = 0;
            for (t=0; a[i][t]; t++)
            {
                for (f=0; a[i][t+f] && a[j][f] &&
                          a[i][t+f] == a[j][f]; f++);
                if (a[i][t+f] == '\0')
                    dat[i][j] = f;
            }
        }

    int num[n], lens = 0, min = -1;
    for (i=0; i<n; i++) lens += strlen(a[i]);
    long _pow_ = pow(2, n) - 1;
    for (i=0; i<n; i++) num[i] = 0;
    while (num[n-1] < n)
    {
        t = 0;
        for (i=0; i<n; i++) t += pow(2, num[i]);

        if (t == _pow_)
        {
            f = lens;
            for (i=1; i<n; i++)
                f -= dat[num[i-1]][num[i]];

            if (f < min || min == -1)
                min = f;
        }

        num[0] += 1;
        for (i=0; i<n-1; i++)
            if (num[i] == n)
            {
                num[i] = 0;
                num[i + 1] += 1;
            }
    }

    printf("%d\n", min);
    return 0;
}
