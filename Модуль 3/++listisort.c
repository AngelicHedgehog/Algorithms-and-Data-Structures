#include <stdio.h>
#include <malloc.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

int main(int argc, char **argv)
{
    struct Elem *a, *b;
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        struct Elem *x = malloc(sizeof(struct Elem));
        scanf("%d", &x->v);
        if (!i)
            a = x;
        else
            {b->next = x; x->prev = b;}
        b = x;
    }
    a->prev = b; b->next = a;

    struct Elem *nxt, *x = a->next, *y;
    for (int i=1; i<n; i++)
    {
        if (x->v < a->v)
            a = x;
        nxt = x->next;
        x->prev->next = x->next;
        x->next->prev = x->prev;

        y = x->prev;
        for (int j=0; j<i && y->v > x->v; j++)
            y = y->prev;
        y = y->next;

        x->next = y;
        x->prev = y->prev;
        y->prev->next = x;
        y->prev = x;

        x = nxt;
    }

    x = a;
    for (int i=0; i<n; i++)
    {
        printf("%d ", x->v);
        if (i == n - 1)
            free(x);
        else
        {
            x = x->next;
            free(x->prev);
        }
    }
    return 0;
}
