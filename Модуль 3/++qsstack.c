#include <stdio.h>

struct Task {
    int low, high;
};

int main(int argc, char **argv)
{
    int n, i, j, hesh, a, b;
    scanf("%d", &n);

    int arr[n];
    for (i=0; i<n; i++) scanf("%d", &arr[i]);

    struct Task stack[n];
    stack[0].low = 0; stack[0].high = n;
    for (i=1; i<n; i++)
        {stack[i].low = i; stack[i].high = i + 1;}

    for (i=0; i<n;)
    {
        if (stack[i].high <= stack[i].low + 1)
            {i++; continue;}
        a = stack[i].low;
        b = stack[i].high - 1;
        while (a < b)
            if (arr[a] < arr[a+1])
            {
                hesh = arr[a+1];
                arr[a+1] = arr[b];
                arr[b] = hesh;
                b--;
            }
            else
            {
                hesh = arr[a+1];
                arr[a+1] = arr[a];
                arr[a] = hesh;
                a++;
            }
        if (a + 1 < n)
        {
            stack[a+1].low = a+1;
            stack[a+1].high = stack[i].high;
        }
        stack[i].high = a;
    }

    for (i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}

