#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char form[4], str[1000001], sub_str[1000001];
    long long i, j, a, b, m, N[28] = {0}, len;

    scanf("%s", str);
    scanf("%lld", &m);
    for (; m; m--)
    {
        scanf("%s %lld ", form, &a);
        if (form[0] == 'U')
        {
            len = strlen(str);
            scanf("%s", sub_str);
            for (i=0; sub_str[i] && a + i < 1000001; i++)
                str[a + i] = sub_str[i];
            if (len < a + i && a + i < 1000001)
                str[a + i] = '\0';
        }
        else
        {
            scanf("%lld", &b);
            for (i=a; i<=b && str[i]; i++)
                N[((int)str[i] - 97) % 28]++;
            N[0] %= 2;
            for (i=1; i<28; i++)
            {
                N[0] += N[i] % 2;
                N[i] = 0;
            }
            printf((b - a + 1) % 2 == N[0] ? "YES\n" : "NO\n");
            N[0] = 0;
        }
    }

    return 0;
}
