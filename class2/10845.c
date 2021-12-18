//중요도!!!!!
//원형 큐(Circular Queue) 구현
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUE_LEN 10000
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _cQueue
{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
int NextPosIdx(int pos);
void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QEPeek(Queue *pq);
Data QPeek(Queue *pq);

int main()
{
    Queue q;
    QueueInit(&q);
    int CNT;
    scanf("%d", &CNT);
    getchar();

    while (CNT--)
    {
        char strOrder[6];
        Data data;
        int size;
        //문자열 입력에 따른 order 정하기
        int order;
        scanf("%s", strOrder);
        getchar();

        if (!strcmp(strOrder, "push"))
            order = 1;
        else if (!strcmp(strOrder, "pop"))
            order = 2;
        else if (!strcmp(strOrder, "size"))
            order = 3;
        else if (!strcmp(strOrder, "empty"))
            order = 4;
        else if (!strcmp(strOrder, "front"))
            order = 5;
        else if (!strcmp(strOrder, "back"))
            order = 6;
        //명령 실행
        switch (order)
        {
        case 1:
            scanf("%d", &data);
            getchar();
            Enqueue(&q, data);
            break;
        case 2:
            printf("%d\n", Dequeue(&q));
            break;
        case 3:
            size = q.rear - q.front;
            size = size < 0 ? size * (-1) : size;
            printf("%d\n", size);
            break;
        case 4:
            printf("%d\n", QIsEmpty(&q));
            break;
        case 5:
            printf("%d\n", QPeek(&q));
            break;
        case 6:
            printf("%d\n", QEPeek(&q));
            break;
        }
    }
}
void QueueInit(Queue *pq)
{
    //큐가 텅 빈 경우 front 와 rear은 동일 위치를 가리킴
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue *pq)
{
    if (pq->front == pq->rear) //큐가 텅 비었다면
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)
{
    if (pos == QUE_LEN - 1) //배열의 마지막 요소의 인덱스 값이라면
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue *pq, Data data)
{
    if (NextPosIdx(pq->rear) == pq->front) //큐가 꽉 찻다면
        exit(-1);

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue *pq)
{
    if (QIsEmpty(pq))
        return -1;
    // exit(-1);

    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}
Data QEPeek(Queue *pq)
{
    if (QIsEmpty(pq))
        return -1;
    return pq->queArr[pq->rear];
}
Data QPeek(Queue *pq)
{
    if (QIsEmpty(pq))
        return -1;
    // exit(-1);

    return pq->queArr[NextPosIdx(pq->front)];
}