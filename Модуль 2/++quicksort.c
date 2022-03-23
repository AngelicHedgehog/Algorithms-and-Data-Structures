#include <stdio.h>

void swap(int *arr, int i, int j)
{
    int buf = arr[i];
    arr[i] = arr[j];
    arr[j] = buf;
}

void qvsort(int *arr, int a, int b, int m)
{
    int sep, end, j; if (m < 2) m = 2;
    while (b - a >= m)
    {
        sep = a; end = b - 1;
        while (sep < end)
            if (arr[sep] > arr[sep + 1])
                swap(arr, sep, sep++);
            else
                swap(arr, sep + 1, end--);
        if (b - sep > sep - a)
        {
            qvsort(arr, a, sep, m);
            a = sep + 1;
        }
        else
        {
            qvsort(arr, sep + 1, b, m);
            b = sep;
        }
    }
    for (int i=a; i<b-1; i++)
    {
        for (sep=i, end=i+1; end<b; end++)
            if (arr[sep] > arr[end])
                sep = end;
        if (sep != i)
            swap(arr, i, sep);
    }
}

int main(int argc, char **argv)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int array[n];
    for (int i=0; i<n; i++) scanf("%d", &array[i]);

    qvsort(array, 0, n, m);

    for (int i=0; i<n; i++) printf("%d ", array[i]); printf("\n");
    return 0;
}
