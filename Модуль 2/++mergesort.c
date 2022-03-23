#include <stdio.h>

void swap(int *arr, int i, int j)
{
    //printf("SWAP %d %d\n", i, j);

    arr[i] = arr[i] + arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] = arr[i] - arr[j];
}

int compare(int *arr, int i, int j)
{
    //printf("COMPARE %d %d\n", i, j);

    int a = abs(arr[i]), b = abs(arr[j]);
    return a == b ? 0 : a > b ? 1 : -1;
}

void msort(int *arr, int a, int b)
{
    if (b - a >= 5)
    {
        int h = (a + b) / 2;
        msort(arr, a, h);
        msort(arr, h, b);

        int arr_[b - a], i = 0, j = 0;
        while (a + i < h || h + j < b)
            if (h + j < b &&
                (a + i == h ||
                 compare(arr, a + i, h + j) == 1))
            {
                arr_[i + j] = arr[h + j];
                j++;
            }
            else
            {
                arr_[i + j] = arr[a + i];
                i++;
            }
        for (i=0; i<b-a; i++) arr[a + i] = arr_[i];
    }
    else
        for (int i=a+1; i<b; i++)
            for (int j=i-1; j>=a && compare(arr, j, j+1)==1; j--)
                swap(arr, j, j+1);
}


int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i=0; i<n; i++) scanf("%d", &array[i]);

    msort(array, 0, n);

    for (int i=0; i<n; i++) printf("%d ", array[i]);printf("\n");
    return 0;
}
/*
9
4 1 2 6 2 3 4 6 2
*/
