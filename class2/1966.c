//중요도!!!!
//큐(Circular Queue) 구현, 우선 순위 입력하여 작동
//원형 큐로는 동작X
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUE_LEN 10000
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef int Priority;
typedef struct _cQueue
{
    int front;
    int rear;
    Data queArr[QUE_LEN];
    Priority pr[QUE_LEN];
} Queue;
//원형 큐 기본 동작 함수
void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
int NextPosIdx(int pos);
void Enqueue(Queue *pq, Data data, Priority pr); //우선순위 고려
Data Dequeue(Queue *pq);
Data QEPeek(Queue *pq);
Data QPeek(Queue *pq);
//우선순위 큐 기본 동작 함수 -> 원형 큐 불가
Priority QPeekPr(Queue *pq);
Priority searchHiPr(Queue *pq);
void changeSEQueue(Queue *pq);

int main()
{
    int N;
    scanf("%d", &N);

    while (N--)
    {
        //데이터 입력 부
        Queue q;
        QueueInit(&q);
        int M;                //입력할 데이터의 개수
        Data idx;             //찾고자 하는 값
        Priority pr[QUE_LEN]; //우선순위 배열
        scanf("%d %d", &M, &idx);
        for (int i = 0; i < M; i++) //우선 순위는 1~9 10개가 존재 높을 수록 우선순위가 높다.
            scanf("%d", &pr[i]);

        for (int i = 0; i < M; i++)
            Enqueue(&q, i, pr[i]);

        int cnt = 0;
        while (1)
        {
            Priority hipr = searchHiPr(&q);
            if (QPeekPr(&q) == hipr)
            {
                if (Dequeue(&q) == idx)
                    break;
                else
                    cnt++;
            }
            else
                changeSEQueue(&q);
        }

        printf("%d\n", cnt + 1);
    }
}
void changeSEQueue(Queue *pq)
{
    //가장 처음 데이터 저장
    Data fdtmp = pq->queArr[NextPosIdx(pq->front)];
    Priority fptmp = pq->pr[NextPosIdx(pq->front)];

    for (int i = NextPosIdx(pq->front); i < pq->rear; i++) //원형 큐 모순 발생
    {
        pq->queArr[i] = pq->queArr[i + 1];
        pq->pr[i] = pq->pr[i + 1];
    }
    pq->queArr[pq->rear] = fdtmp;
    pq->pr[pq->rear] = fptmp;
}
Priority searchHiPr(Queue *pq)
{
    int max;
    for (int i = NextPosIdx(pq->front); i <= pq->rear; i++) //원형 큐 모순 발생
    {
        if (max < pq->pr[i] || i == NextPosIdx(pq->front))
            max = pq->pr[i];
    }
    // printf("font: %d rear: %d max: %d\n", NextPosIdx(pq->front), pq->rear, max);
    return max;
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

void Enqueue(Queue *pq, Data data, Priority pr) // data push
{
    if (NextPosIdx(pq->rear) == pq->front) //큐가 꽉 찻다면
        exit(-1);

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
    pq->pr[pq->rear] = pr;
}

Data Dequeue(Queue *pq) // data pop
{
    if (QIsEmpty(pq))
        return -1;
    // exit(-1);

    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}
Data QEPeek(Queue *pq) //맨 마지막 인자를 보여준다.
{
    if (QIsEmpty(pq))
        return -1;
    return pq->queArr[pq->rear];
}
Data QPeek(Queue *pq) //맨 처음 인자를 보여준다.
{
    if (QIsEmpty(pq))
        return -1;
    // exit(-1);

    return pq->queArr[NextPosIdx(pq->front)];
}
Priority QPeekPr(Queue *pq)
{
    if (QIsEmpty(pq))
        return 1;
    return pq->pr[NextPosIdx(pq->front)];
}