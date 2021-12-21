//중요도!!!!!
//원형큐 Circle Queue
#include <stdio.h>
#include <stdlib.h>
#define QUE_SIZE 500001 // 1<=N<=500000
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _cQueue
{
    int front;
    int rear;
    Data queArr[QUE_SIZE];
} Queue;

void QueueInit(Queue *pq); // Queue 초기화
int QIsEmpty(Queue *pq);   // Queue가 비었는지 확인
int NextPosIdx(int pos);   // font의 위치 알려줌

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

int main()
{
    Queue q;
    QueueInit(&q);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        Enqueue(&q, i);

    Data pop;
    while (1)
    {
        pop = Dequeue(&q);
        if (QIsEmpty(&q))
            break;
        Enqueue(&q, Dequeue(&q));
    }
    printf("%d", pop);
}

void QueueInit(Queue *pq)
{
    // Queue가 빈 경우 동일한 font, rear를 가짐
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