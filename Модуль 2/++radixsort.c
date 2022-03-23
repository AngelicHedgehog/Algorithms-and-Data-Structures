#include <stdio.h>
#include <string.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void rsort(union Int32 *arr, size_t nel)
{
    int N[256], i, j;
    union Int32 NEW[nel];
    for (int b=0; b<3; b++)
    {
        for (i=0; i<256; i++) N[i] = 0;
        for (i=0; i<nel; i++) N[arr[i].bytes[b]]++;
        for (i=1; i<256; i++) N[i] += N[i-1];
        for (i=nel-1; i>=0; i--) NEW[--N[arr[i].bytes[b]]] = arr[i];
        for (i=0; i<nel; i++) arr[i] = NEW[i];
    }
    for (i=0; i<256; i++) N[i] = 0;
    for (i=0; i<nel; i++) N[arr[i].bytes[3]^128]++;
    for (i=1; i<256; i++) N[i] += N[i-1];
    for (i=nel-1; i>=0; i--) NEW[--N[arr[i].bytes[3]^128]] = arr[i];
    for (i=0; i<nel; i++) arr[i] = NEW[i];
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);

    union Int32 dat[n];
    for (int i=0; i<n; i++) scanf("%d", &dat[i].x);

    rsort(dat, n);

    for (int i=0; i<n; i++) printf("%d ", dat[i].x);
    return 0;
}
