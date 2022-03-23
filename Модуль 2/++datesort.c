#include <stdio.h>

struct Date {
    int Day, Month, Year;
};

int compare_day(struct Date a, struct Date b)
{
    return a.Day == b.Day ? 0 : a.Day > b.Day ? 1 : -1;
}

int compare_month(struct Date a, struct Date b)
{
    return a.Month == b.Month ? 0 : a.Month > b.Month ? 1 : -1;
}

int compare_year(struct Date a, struct Date b)
{
    return a.Year == b.Year ? 0 : a.Year > b.Year ? 1 : -1;
}

void insort(struct Date *arr, size_t n,
        int (*compare)(struct Date a, struct Date b))
{
    for (int i=1; i<n; i++)
        for (int j=i-1; j>=0 && compare(arr[j], arr[j+1])==1; j--)
        {
            struct Date t = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = t;
        }
}

void chgsort(struct Date *arr, size_t n)
{
    insort(arr, n, compare_day);
    insort(arr, n, compare_month);
    insort(arr, n, compare_year);
}


int main(int argc, char **argv)
{
    int n, i, j;
    scanf("%d", &n);
    struct Date arr[n];
    for (i=0; i<n; i++) scanf("%d %d %d", &arr[i].Year,
                                          &arr[i].Month,
                                          &arr[i].Day);

    chgsort(arr, n);

    for (i=0; i<n; i++)
        printf("%04d %02d %02d\n", arr[i].Year,
                                   arr[i].Month,
                                   arr[i].Day);
    return 0;
}
