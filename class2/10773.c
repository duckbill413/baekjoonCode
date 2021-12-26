//중요도!!!!
//스택
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100001
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _stack
{
    int topIdx;
    Data stackArr[STACK_SIZE];
} Stack;
void Init(Stack *st);
int isEmpty(Stack *st);
void Push(Stack *st, Data data);
Data Pop(Stack *st);
int getSum(Stack *st);

int main()
{
    Stack stack;
    Init(&stack);
    int K;
    scanf("%d", &K);
    while (K--)
    {
        Data val;
        scanf("%d", &val);
        if (val != 0)
            Push(&stack, val);
        else
            Pop(&stack);
    }
    printf("%d", getSum(&stack));
}

void Init(Stack *st)
{
    st->topIdx = -1;
}
int isEmpty(Stack *st)
{
    if (st->topIdx == -1)
        return TRUE;
    else
        return FALSE;
}
void Push(Stack *st, Data data)
{
    st->topIdx += 1;
    st->stackArr[st->topIdx] = data;
}
Data Pop(Stack *st)
{
    if (isEmpty(st))
        exit(0);
    int ridx = st->topIdx;
    st->topIdx -= 1;
    return st->stackArr[ridx];
}
int getSum(Stack *st)
{
    int sum = 0;
    while (!isEmpty(st))
    {
        sum += Pop(st);
    }
    return sum;
}