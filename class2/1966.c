//�߿䵵!!!!
//ť(Circular Queue) ����, �켱 ���� �Է��Ͽ� �۵�
//���� ť�δ� ����X
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
//���� ť �⺻ ���� �Լ�
void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
int NextPosIdx(int pos);
void Enqueue(Queue *pq, Data data, Priority pr); //�켱���� ���
Data Dequeue(Queue *pq);
Data QEPeek(Queue *pq);
Data QPeek(Queue *pq);
//�켱���� ť �⺻ ���� �Լ� -> ���� ť �Ұ�
Priority QPeekPr(Queue *pq);
Priority searchHiPr(Queue *pq);
void changeSEQueue(Queue *pq);

int main()
{
    int N;
    scanf("%d", &N);

    while (N--)
    {
        //������ �Է� ��
        Queue q;
        QueueInit(&q);
        int M;                //�Է��� �������� ����
        Data idx;             //ã���� �ϴ� ��
        Priority pr[QUE_LEN]; //�켱���� �迭
        scanf("%d %d", &M, &idx);
        for (int i = 0; i < M; i++) //�켱 ������ 1~9 10���� ���� ���� ���� �켱������ ����.
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
    //���� ó�� ������ ����
    Data fdtmp = pq->queArr[NextPosIdx(pq->front)];
    Priority fptmp = pq->pr[NextPosIdx(pq->front)];

    for (int i = NextPosIdx(pq->front); i < pq->rear; i++) //���� ť ��� �߻�
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
    for (int i = NextPosIdx(pq->front); i <= pq->rear; i++) //���� ť ��� �߻�
    {
        if (max < pq->pr[i] || i == NextPosIdx(pq->front))
            max = pq->pr[i];
    }
    // printf("font: %d rear: %d max: %d\n", NextPosIdx(pq->front), pq->rear, max);
    return max;
}
void QueueInit(Queue *pq)
{
    //ť�� �� �� ��� front �� rear�� ���� ��ġ�� ����Ŵ
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue *pq)
{
    if (pq->front == pq->rear) //ť�� �� ����ٸ�
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)
{
    if (pos == QUE_LEN - 1) //�迭�� ������ ����� �ε��� ���̶��
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue *pq, Data data, Priority pr) // data push
{
    if (NextPosIdx(pq->rear) == pq->front) //ť�� �� ���ٸ�
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
Data QEPeek(Queue *pq) //�� ������ ���ڸ� �����ش�.
{
    if (QIsEmpty(pq))
        return -1;
    return pq->queArr[pq->rear];
}
Data QPeek(Queue *pq) //�� ó�� ���ڸ� �����ش�.
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