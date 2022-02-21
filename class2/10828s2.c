// 중요도!!!!!
// Stack_List base
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define STACK_LEN 10000
typedef int Data;
typedef struct _node
{
    Data data;
    struct _node *next;
} Node;
typedef struct _listStack
{
    Node *head;
} ListStack;
typedef ListStack Stack;

int selectOrder(char *pstr);
void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);
void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);
int SgetSize(Stack *pstack);

int main()
{
    Stack stack;
    StackInit(&stack);
    int N;
    scanf("%d", &N);

    while (N--)
    {
        char select[6];
        scanf("%s", select);
        getchar();
        Data insert;
        switch (selectOrder(select))
        {
        case 1:
            scanf("%d", &insert);
            getchar();
            SPush(&stack, insert);
            break;
        case 2:
            printf("%d\n", SPop(&stack));
            break;
        case 3:
            printf("%d\n", SgetSize(&stack));
            break;
        case 4:
            printf("%d\n", SIsEmpty(&stack));
            break;
        case 5:
            printf("%d\n", SPeek(&stack));
            break;
        }
    }
}

int selectOrder(char *pstr)
{
    int sel;
    if (!strcmp(pstr, "push"))
        sel = 1;
    else if (!strcmp(pstr, "pop"))
        sel = 2;
    else if (!strcmp(pstr, "size"))
        sel = 3;
    else if (!strcmp(pstr, "empty"))
        sel = 4;
    else if (!strcmp(pstr, "top"))
        sel = 5;
    return sel;
}

int SgetSize(Stack *pstack)
{
    int cnt = 0;
    if (!SIsEmpty(pstack))
    {
        Stack tmp = *pstack;
        while (tmp.head != NULL)
        {
            cnt++;
            tmp.head = tmp.head->next;
        }
    }
    return cnt;
}
void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

Data SPop(Stack *pstack)
{
    Data rdata;
    Node *rnode;
    if (SIsEmpty(pstack))
        return -1;

    rdata = pstack->head->data;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    free(rnode);
    return rdata;
}

Data SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack))
        return -1;
    return pstack->head->data;
}