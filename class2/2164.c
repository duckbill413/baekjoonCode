//�߿䵵!!!!!
//����ť Circle Queue
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

void QueueInit(Queue *pq); // Queue �ʱ�ȭ
int QIsEmpty(Queue *pq);   // Queue�� ������� Ȯ��
int NextPosIdx(int pos);   // font�� ��ġ �˷���

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
    // Queue�� �� ��� ������ font, rear�� ����
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