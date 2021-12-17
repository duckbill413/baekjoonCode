// �߿䵵!!!!!
// Stack�� ó�� pop, push
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define STACK_LEN 100000
#define STACK_OUT_LEN 400000
typedef int Data; //������ Data �Է�

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} Stack;

void StackInit(Stack *pstack);        // Stack �ʱ�ȭ
int SIsEmpty(Stack *pstack);          // Stack �� ��������� Ȯ��
int SIsFull(Stack *pstack);           // Stack�� ������� �ִ��� Ȯ��
void SPush(Stack *pstack, Data data); //�����͸� ��ȯ�ϰ� ����
Data SPop(Stack *pstack);             //�����͸� ��ȯ�ϰ� ����
Data SPeek(Stack *pstack);            //������ ��ȯ

int main()
{
    Stack stack;       // ���� ����ü ����
    StackInit(&stack); //���� index �ʱ�ȭ

    int N;
    scanf("%d", &N);

    Data data = 1; // push�� ������
    //ã�����ϴ� ������ �� �Է�
    Data *search = (Data *)malloc(sizeof(Data) * N);
    for (Data *psearch = search; psearch < search + N; psearch++)
        scanf("%d", psearch);
    Data *psearch = search;
    //+, -�� ����ϱ� ���� ���Ḯ��Ʈ ����

    char output[STACK_OUT_LEN];
    int outIndex = 0;
    while (1)
    {
        if (*psearch > SPeek(&stack) || data == 1)
        {
            SPush(&stack, data);
            data++;
            output[outIndex++] = '+';
        }
        else
        {
            Data pop = SPop(&stack);
            if (pop == *psearch)
            {
                output[outIndex++] = '-';
                psearch++;
                if (psearch == (search + N))
                    break;
            }
            else
            {
                printf("NO");
                return 0;
            }
        }
    }

    for (int i = 0; i < outIndex; i++)
        printf("%c\n", output[i]);
}
void StackInit(Stack *pstack) //���� �ʱ�ȭ(index�� �ʱ�ȭ ��Ŵ���μ�)
{
    pstack->topIndex = -1; // topIndex�� -1�� �� ����
}

int SIsEmpty(Stack *pstack) // Stack �� ��������� Ȯ��
{
    if (pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}
int SIsFull(Stack *pstack)
{
    if (pstack->topIndex == STACK_LEN)
        return TRUE;
    else
        return FALSE;
}
void SPush(Stack *pstack, Data data) //�����͸� ��ȯ�ϰ� ����
{
    if (SIsFull(pstack)) //����� Ȯ��
        exit(-1);

    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack)
{
    if (SIsEmpty(pstack)) //������ Ȯ��
    {
        return FALSE;
        // exit(-1);
    }

    int rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArr[rIdx];
}

Data SPeek(Stack *pstack) //������ ��ȯ
{
    if (SIsEmpty(pstack))
    {
        return FALSE;
        // exit(-1);
    }
    return pstack->stackArr[pstack->topIndex];
}