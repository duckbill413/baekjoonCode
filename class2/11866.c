//중요도!!!!
// 원형큐, 요세푸스 문제
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define QUE_SIZE 1001 //원형큐를 사용하므로 주어진 크기+1을 할당해야 한다.
typedef int Data;
typedef struct _queue
{
    int front;
    int rear;
    Data queArr[QUE_SIZE];
} Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
int NextPosIdx(int pos);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    Queue queue;
    QueueInit(&queue);

    for (int i = 1; i <= N; i++)
        Enqueue(&queue, i);

    int cnt = 0;

    printf("<");
    while (!QIsEmpty(&queue))
    {
        if (cnt == K - 1)
        {
            printf("%d", Dequeue(&queue));
            if (!QIsEmpty(&queue))
                printf(", ");
            cnt = 0;
        }
        else
        {
            Enqueue(&queue, Dequeue(&queue));
            cnt++;
        }
    }
    printf(">");
}
void QueueInit(Queue *pq)
{
    pq->front = 0;
    pq->rear = 0;
}
int QIsEmpty(Queue *pq)
{
    if (pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}
int NextPosIdx(int pos)
{
    if (pos == QUE_SIZE - 1)
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue *pq, Data data)
{
    if (NextPosIdx(pq->rear) == pq->front)
        exit(0);
    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}
Data Dequeue(Queue *pq)
{
    if (QIsEmpty(pq))
        exit(0);
    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}
Data QPeek(Queue *pq)
{
    if (QIsEmpty(pq))
        exit(0);
    return pq->queArr[NextPosIdx(pq->front)];
}