#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *arr, size_t i, size_t j, size_t w)
{
    char *l = arr + i * w,
         *r = arr + j * w,
         *h = malloc(w);
    memcpy(h, r, w);
    memcpy(r, l, w);
    memcpy(l, h, w);
    free(h);
}

int compare(const void *a, const void *b)
{
    char *A = (char*)a, *B = (char*)b;
    int a_ = 0, b_ = 0;
    for (int i=0; A[i]!='\0'; i++)
        if (A[i] == 'a')
            a_++;
    for (int i=0; B[i]!='\0'; i++)
        if (B[i] == 'a')
            b_++;
    return a_ == b_ ? 0 : a_ > b_ ? 1 : -1;
}

void heapify(char *B, size_t n, size_t i, size_t wh,
        int (*compare)(const void *a, const void *b))
{
    int l = i * 2 + 1, r = i * 2 + 2;
    char *T = B + i * wh, *L = B + l * wh, *R = B + r * wh;
    if (l < n && compare(L, T) == 1 && (r >= n || compare(L, R) == 1))
    {
        swap(B, i, l, wh);
        heapify(B, n, l, wh, compare);
    }
    else if (r < n && compare(R, T) == 1)
    {
        swap(B, i, r, wh);
        heapify(B, n, r, wh, compare);
    }
}

void hsort(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b))
{
    char *bas = (char*)base;
    for (int n=nel; n>1; n--)
    {
        for (int i=(n-1)/2; i>=0; i--)
            heapify(bas, n, i, width, compare);
        swap(bas, 0, n - 1, width);
    }
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d ", &n);
    char array[n][1000];
    for (int i=0; i<n; i++)
    {
        fgets(array[i], 1000, stdin);
        array[i][strlen(array[i])-1] = '\0';
    }
    hsort(array, n, sizeof(array[0]), compare);
    for (int i=0; i<n; i++) printf("%s\n", array[i]);
}
