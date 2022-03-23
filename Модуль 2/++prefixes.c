#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *str = argv[1];
    int len = strlen(str), flag, d, i, j, a, k;
    for (i=0; !i || str[i-1]; i++)
        for (j=i; j>1; j--)
            if (i % j == 0)
            {
                d = i / j;
                for (a=0; a<d; a++)
                {
                    for (k=1; k<j; k++)
                        if (str[a+k*d] != str[a+(k-1)*d])
                            break;
                    if (k != j)
                        break;
                }
                if (a == d)
                {
                    printf("%d %d\n", i, j);
                    break;
                }
            }
    return 0;
}
