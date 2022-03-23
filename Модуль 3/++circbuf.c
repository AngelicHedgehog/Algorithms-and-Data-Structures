#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue
{
    long long *data;
    int cap, count, head, tail;
};

void InitQueue(struct Queue *q, int n)
{
    q->data = (long long *)malloc(sizeof(long long) * n);
    q->cap = n; q->count = 0; q->head = 0; q->tail = 0;
}

int QueueEmpty(struct Queue q)
{
    return q.count == 0;
}

void Enqueue(struct Queue *q, long long x)
{
    if (q->count == q->cap)
    {
        q->data = (long long *)realloc(q->data, sizeof(long long)*q->cap*2);
        for (int i=0; i<q->tail; i++)
            q->data[i+q->cap] = q->data[i];
        q->tail += q->cap;
        q->cap *= 2;
    }
    q->data[q->tail] = x;
    q->tail++;
    if (q->tail == q->cap)
        q->tail = 0;
    q->count++;
}

long long Dequeue(struct Queue *q)
{
    long long x = q->data[q->head];
    q->head++;
    if (q->head == q->cap)
        q->head = 0;
    q->count--;
    return x;
}

int main(int argc, char **argv)
{
    struct Queue queue;
    InitQueue(&queue, 4);

    int n;
    char command[6];
    long long x;

    scanf("%d", &n);
    for (; n; n--)
    {
        scanf("%s", &command);
        if (!strcmp(command, "ENQ"))
        {
            scanf("%lld", &x);
            Enqueue(&queue, x);
        }
        else if (!strcmp(command, "DEQ"))
        {
            printf("%lld\n", Dequeue(&queue));
        }
        else if (!strcmp(command, "EMPTY"))
        {
            printf(QueueEmpty(queue) ? "true\n" : "false\n");
        }
    }
    free(queue.data);
    return 0;
}
