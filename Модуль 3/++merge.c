#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int *arr, top, n;
};

struct PrQueue
{
    struct Element *heap;
    int (*cmp)(struct Element, struct Element);
    int cap, count;
};

int compare(struct Element a, struct Element b)
{
    if (b.top == b.n)
        return -1;
    if (a.top == a.n)
        return 1;
    return a.arr[a.top] - b.arr[b.top];
}

void InitPriorityQueue(struct PrQueue *q, int n,
            int (*cmp)(struct Element, struct Element))
{
    q->heap = (struct Element *)malloc(sizeof(struct Element) * n);
    q->cmp = cmp; q->cap = n; q->count = 0;
}

struct Element Maximum(struct PrQueue q)
{
    return q.heap[0];
};

void Insert(struct PrQueue *q, struct Element ptr)
{
    int i = q->count;
    q->count++;
    q->heap[i] = ptr;
    struct Element buffer;
    while (i > 0 && q->cmp(q->heap[(i-1)/2], q->heap[i]) > 0)
    {
        buffer = q->heap[(i-1)/2];
        q->heap[(i-1)/2] = q->heap[i];
        q->heap[i] = buffer;
        i = (i - 1) / 2;
    }
}

void Heapify(struct PrQueue *q, int i, int n)
{
    struct Element buffer;
    int l, r, j;
    while (1)
    {
        l = 2 * i + 1; r = l + 1; j = i;
        if (l < n && q->cmp(q->heap[i], q->heap[l]) > 0) i = l;
        if (r < n && q->cmp(q->heap[i], q->heap[r]) > 0) i = r;
        if (i == j) break;
        buffer = q->heap[i];
        q->heap[i] = q->heap[j];
        q->heap[j] = buffer;
    }
}

void IncreaseKey(struct PrQueue *q)
{
    int i = 0;
    struct Element buffer;
    Heapify(q, 0, q->cap);
}

int main(int argc, char **argv)
{
    int k;
    scanf("%d", &k);

    struct PrQueue prqueue;
    InitPriorityQueue(&prqueue, k, compare);

    int n[k];
    for (int i=0; i<k; i++) scanf("%d", &n[i]);

    struct Element ptr;
    for (int i=0; i<k; i++)
    {
        ptr.n = n[i]; ptr.top = 0;
        ptr.arr = (int *)malloc(sizeof(int) * n[i]);
        for (int j=0; j<n[i]; j++)
            scanf("%d", &ptr.arr[j]);
        Insert(&prqueue, ptr);
    }

    while (prqueue.heap[0].top != prqueue.heap[0].n)
    {
        printf("%d ", prqueue.heap[0].arr[prqueue.heap[0].top]);
        prqueue.heap[0].top++;
        IncreaseKey(&prqueue);
    }

    for (int i=0; i<prqueue.cap; i++)
        free(prqueue.heap[i].arr);
    free(prqueue.heap);
    return 0;
}
