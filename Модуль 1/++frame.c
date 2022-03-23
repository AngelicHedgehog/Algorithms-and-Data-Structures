#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    int a = 0, b = 0, len = strlen(argv[3]);
    for (int i=0; argv[1][i]; i++)
        a = a * 10 + argv[1][i] - '0';
    for (int i=0; argv[2][i]; i++)
        b = b * 10 + argv[2][i] - '0';

    if (len + 2 > b)
    {
        printf("Error\n");
        return 0;
    }

    int I = (a - 1) / 2, J = (b - 1) / 2 - len / 2;
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<b; j++)
            if (i == I && j == J)
            {
                printf("%s", argv[3]);
                j += len - 1;
            }
            else
                printf(i==0||j==0||i==a-1||j==b-1?"*":" ");
        printf("\n");
    }
    return 0;
}
