//�߿䵵!!!!!
// Stack_Array base
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_LEN 10000
#define TRUE 1
#define FALSE 0
typedef int Data;
typedef struct _stack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} Stack;

int selectOrder(char *pstr);
void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);
void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);
int SSize(Stack *pstack);

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
            printf("%d\n", SSize(&stack));
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
int SSize(Stack *pstack)
{
    return pstack->topIndex + 1;
}
void StackInit(Stack *pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack)
{
    if (SIsEmpty(pstack))
        return -1;

    int idx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArr[idx];
}

Data SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack))
        return -1;
    return pstack->stackArr[pstack->topIndex];
}