#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    int n, m, i, j;
    scanf("%d%d", &n, &m);

    long long el,
    a0, a1, a2, a3, a4,
    a5, a6, a7, a8, a9,
    b0, b1, b2, b3, b4,
    b5, b6, b7, b8, b9;

    for (i = 0; i<n; i++)
        for (j = 0; j<m; j++)
        {
            scanf("%lld", &el);
            if (i == 0 & (j == 0 | el > a0)) a0 = el;
            else if (i == 1 & (j == 0 | el > a1)) a1 = el;
            else if (i == 2 & (j == 0 | el > a2)) a2 = el;
            else if (i == 3 & (j == 0 | el > a3)) a3 = el;
            else if (i == 4 & (j == 0 | el > a4)) a4 = el;
            else if (i == 5 & (j == 0 | el > a5)) a5 = el;
            else if (i == 6 & (j == 0 | el > a6)) a6 = el;
            else if (i == 7 & (j == 0 | el > a7)) a7 = el;
            else if (i == 8 & (j == 0 | el > a8)) a8 = el;
            else if (i == 9 & (j == 0 | el > a9)) a9 = el;
            if (j == 0 & (i == 0 | el < b0)) b0 = el;
            else if (j == 1 & (i == 0 | el < b1)) b1 = el;
            else if (j == 2 & (i == 0 | el < b2)) b2 = el;
            else if (j == 3 & (i == 0 | el < b3)) b3 = el;
            else if (j == 4 & (i == 0 | el < b4)) b4 = el;
            else if (j == 5 & (i == 0 | el < b5)) b5 = el;
            else if (j == 6 & (i == 0 | el < b6)) b6 = el;
            else if (j == 7 & (i == 0 | el < b7)) b7 = el;
            else if (j == 8 & (i == 0 | el < b8)) b8 = el;
            else if (j == 9 & (i == 0 | el < b9)) b9 = el;
        };
    el = 0;
    for (i = 0; i<n; i++)
    {
        if (i == 1) a0 = a1;
        else if (i == 2) a0 = a2;
        else if (i == 3) a0 = a3;
        else if (i == 4) a0 = a4;
        else if (i == 5) a0 = a5;
        else if (i == 6) a0 = a6;
        else if (i == 7) a0 = a7;
        else if (i == 8) a0 = a8;
        else if (i == 9) a0 = a9;
        for (j = 0; j<m; j++)
        {
            if (j == 0 & a0 == b0) printf("%d %d\n", i, j);
            else if (j == 1 & a0 == b1) printf("%d %d\n", i, j);
            else if (j == 2 & a0 == b2) printf("%d %d\n", i, j);
            else if (j == 3 & a0 == b3) printf("%d %d\n", i, j);
            else if (j == 4 & a0 == b4) printf("%d %d\n", i, j);
            else if (j == 5 & a0 == b5) printf("%d %d\n", i, j);
            else if (j == 6 & a0 == b6) printf("%d %d\n", i, j);
            else if (j == 7 & a0 == b7) printf("%d %d\n", i, j);
            else if (j == 8 & a0 == b8) printf("%d %d\n", i, j);
            else if (j == 9 & a0 == b9) printf("%d %d\n", i, j);
            else if (j == m - 1 & i == n - 1) printf("none\n");
            else continue;
            el = 1;
            break;
        };
        if (el) break;
    };

    return 0;
}
