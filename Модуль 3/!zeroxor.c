#include <stdio.h>

int main(int argc, char **argv)
{
    int n, ind = -1, count_all = 0, count = 0, zero, j;
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        zero = 0;
        for (j=i; j>ind; j--)
        {
            zero ^= arr[j];
            if (!zero)
                {count++; ind = i; break;}
        }
        printf("%d %d %d\n", i, j, zero);
        if (j-1 != ind && count)
        {
            count_all += (count + 1) * count / 2;
            count = 0;
        }
    }

    printf("%d\n", count_all + (count + 1) * count / 2);
    return 0;
}
