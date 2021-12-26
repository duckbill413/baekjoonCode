//�߿䵵!!!!!
// Array based stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 200
#define TRUE 1
#define FALSE 0

typedef char Data;
typedef struct _stack
{
    int topIndex;
    Data stackArr[STACK_SIZE];
} Stack;
void StackInit(Stack *ps);
int SIsEmpty(Stack *ps);
void SPush(Stack *ps, Data data);
Data SPop(Stack *ps);
Data SPeek(Stack *ps);
int balanceStr(Stack *q, char *ch);
int main()
{
    char str[102];
    while (1)
    {
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = 0;
        if (strcmp(str, ".") == 0)
            break;
        Stack stack;
        StackInit(&stack);

        if (balanceStr(&stack, str))
            printf("yes\n");
        else
            printf("no\n");
    }
}
int balanceStr(Stack *q, char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
        {
            if (SIsEmpty(q))
                SPush(q, str[i]);
            else
            {
                if (SPeek(q) == '(' && str[i] == ')')
                    SPop(q);
                else if (SPeek(q) == '[' && str[i] == ']')
                    SPop(q);
                else
                    SPush(q, str[i]);
            }
        }
    }
    if (SIsEmpty(q))
        return TRUE;
    else
        return FALSE;
}
void StackInit(Stack *ps)
{
    ps->topIndex = -1;
}
int SIsEmpty(Stack *ps)
{
    if (ps->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}
void SPush(Stack *ps, Data data)
{
    ps->topIndex += 1;
    ps->stackArr[ps->topIndex] = data;
}
Data SPop(Stack *ps)
{
    if (SIsEmpty(ps))
        return -1;
    int rIdx = ps->topIndex;
    ps->topIndex -= 1;
    return ps->stackArr[rIdx];
}
Data SPeek(Stack *ps)
{
    if (SIsEmpty(ps))
        return -1;
    return ps->stackArr[ps->topIndex];
}