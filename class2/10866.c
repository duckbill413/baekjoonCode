//�߿䵵!!!!!
// Queue upgrade Deque
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUE_SIZE 10000
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node
{
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;
typedef struct _dlDeque
{
    Node *head;
    Node *tail;
} Deque;

void DequeInit(Deque *pdeq);     //���� �ʱ�ȭ
int DIsEmpty(Deque *pdeq);       //���� ä�������� Ȯ��
void DQAddFront(Deque *pdeq);    // front�� data �߰�
void DQAddRear(Deque *pdeq);     // rear�� data �߰�
Data DQRemoveFront(Deque *pdeq); // front�� data�� ��ȯ �� �Ҹ�
Data DQRemoveRear(Deque *pdeq);  // rear�� data�� ��ȯ �� �Ҹ�
Data DQGetFront(Deque *pdeq);    // front�� data�� �Ҹ����� �ʰ� ��ȯ
Data DQGetRear(Deque *pdeq);     // rear�� data�� �Ҹ����� �ʰ� ��ȯ
int DQgetSize(Deque *pdeq);      // Deque�� ����� ��ȯ
void DequeInit(Deque *pdeq);     //���� �ʱ�ȭ
int selectOrder(char *pstr);
int main()
{
    Deque que;
    DequeInit(&que);
    int N;
    int size = 0;
    scanf("%d", &N);

    while (N--)
    {
        char select[20];
        scanf("%s", select);
        getchar();
        switch (selectOrder(select))
        {
        case 1:

            DQAddFront(&que);
            size++;
            break;
        case 2:
            DQAddRear(&que);
            size++;
            break;
        case 3:
            printf("%d\n", DQRemoveFront(&que));
            if (size != 0)
                size--;
            break;
        case 4:
            printf("%d\n", DQRemoveRear(&que));
            if (size != 0)
                size--;
            break;
        case 5:
            printf("%d\n", size);
            break;
        case 6:
            printf("%d\n", DIsEmpty(&que));
            break;
        case 7:
            printf("%d\n", DQGetFront(&que));
            break;
        case 8:
            printf("%d\n", DQGetRear(&que));
            break;
        }
    }
}
int selectOrder(char *pstr)
{
    int sel;
    if (!strcmp(pstr, "push_front"))
        sel = 1;
    else if (!strcmp(pstr, "push_back"))
        sel = 2;
    else if (!strcmp(pstr, "pop_front"))
        sel = 3;
    else if (!strcmp(pstr, "pop_back"))
        sel = 4;
    else if (!strcmp(pstr, "size"))
        sel = 5;
    else if (!strcmp(pstr, "empty"))
        sel = 6;
    else if (!strcmp(pstr, "front"))
        sel = 7;
    else if (!strcmp(pstr, "back"))
        sel = 8;
    return sel;
}
void DequeInit(Deque *pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}
int DIsEmpty(Deque *pdeq) //���� ä�������� Ȯ��
{
    if (pdeq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DQAddFront(Deque *pdeq) // front�� data �߰�
{
    Data data;
    scanf("%d", &data);
    getchar();

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pdeq->head;

    if (DIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev = newNode;

    newNode->prev = NULL;
    pdeq->head = newNode;
}
void DQAddRear(Deque *pdeq) // rear�� data �߰�
{
    Data data;
    scanf("%d", &data);
    getchar();

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pdeq->tail;

    if (DIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail = newNode;
}
Data DQRemoveFront(Deque *pdeq) // front�� data�� ��ȯ �� �Ҹ�
{
    Node *rnode = pdeq->head;
    Data rdata;
    if (DIsEmpty(pdeq))
        return -1;

    rdata = pdeq->head->data;

    pdeq->head = pdeq->head->next;
    free(rnode);

    if (pdeq->head == NULL)
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;

    return rdata;
}
Data DQRemoveRear(Deque *pdeq) // rear�� data�� ��ȯ �� �Ҹ�
{
    Node *rnode = pdeq->tail;
    Data rdata;
    if (DIsEmpty(pdeq))
        return -1;
    rdata = pdeq->tail->data;

    pdeq->tail = pdeq->tail->prev;
    free(rnode);

    if (pdeq->tail == NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;

    return rdata;
}
Data DQGetFront(Deque *pdeq) // front�� data�� �Ҹ����� �ʰ� ��ȯ
{
    if (DIsEmpty(pdeq))
        return -1;
    return pdeq->head->data;
}

Data DQGetRear(Deque *pdeq) // rear�� data�� �Ҹ����� �ʰ� ��ȯ
{
    if (DIsEmpty(pdeq))
        return -1;
    return pdeq->tail->data;
}