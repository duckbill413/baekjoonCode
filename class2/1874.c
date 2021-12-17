// 중요도!!!!!
// Stack의 처리 pop, push
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define STACK_LEN 100000
#define STACK_OUT_LEN 400000
typedef int Data; //정수형 Data 입력

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} Stack;

void StackInit(Stack *pstack);        // Stack 초기화
int SIsEmpty(Stack *pstack);          // Stack 이 빈공간인지 확인
int SIsFull(Stack *pstack);           // Stack에 빈공간이 있는지 확인
void SPush(Stack *pstack, Data data); //데이터를 반환하고 삭제
Data SPop(Stack *pstack);             //데이터를 반환하고 삭제
Data SPeek(Stack *pstack);            //데이터 반환

int main()
{
    Stack stack;       // 스택 구조체 선언
    StackInit(&stack); //스택 index 초기화

    int N;
    scanf("%d", &N);

    Data data = 1; // push할 데이터
    //찾고자하는 데이터 값 입력
    Data *search = (Data *)malloc(sizeof(Data) * N);
    for (Data *psearch = search; psearch < search + N; psearch++)
        scanf("%d", psearch);
    Data *psearch = search;
    //+, -를 출력하기 위한 연결리스트 생성

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
void StackInit(Stack *pstack) //스택 초기화(index를 초기화 시킴으로서)
{
    pstack->topIndex = -1; // topIndex의 -1은 빈 상태
}

int SIsEmpty(Stack *pstack) // Stack 이 빈공간인지 확인
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
void SPush(Stack *pstack, Data data) //데이터를 반환하고 삭제
{
    if (SIsFull(pstack)) //빈공간 확인
        exit(-1);

    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack)
{
    if (SIsEmpty(pstack)) //데이터 확인
    {
        return FALSE;
        // exit(-1);
    }

    int rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArr[rIdx];
}

Data SPeek(Stack *pstack) //데이터 반환
{
    if (SIsEmpty(pstack))
    {
        return FALSE;
        // exit(-1);
    }
    return pstack->stackArr[pstack->topIndex];
}