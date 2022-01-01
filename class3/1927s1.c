//중요도!!!!!
//우선순위 큐(우선순위 힙)
// C로 구현
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100002

typedef int Data;
typedef int PriorityComp(Data d1, Data d2);

typedef struct _heap
{
    PriorityComp *comp;
    int numOfData;
    Data heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);
void HInsert(Heap *ph, Data data);
Data HDelete(Heap *ph);

int GetParentIdx(int idx);
int GetLChildIdx(int idx);
int GetRChildIdx(int idx);
int GetHiPriChildIdx(Heap *ph, int idx);

int DataPriorityComp(Data d1, Data d2)
{
    return d2 - d1;
}
int main()
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    int N;
    scanf("%d", &N);
    while (N--)
    {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 0)
        {
            if (HIsEmpty(&heap))
                printf("0\n");
            else
                printf("%d\n", HDelete(&heap));
        }
        else
            HInsert(&heap, tmp);
    }
}
int GetParentIdx(int idx)
{
    return idx / 2;
}
int GetLChildIdx(int idx)
{
    return idx * 2;
}
int GetRChildIdx(int idx)
{
    return GetLChildIdx(idx) + 1;
}
int GetHiPriChildIdx(Heap *ph, int idx)
{
    if (GetLChildIdx(idx) > ph->numOfData)
        return 0;
    else if (GetLChildIdx(idx) == ph->numOfData)
        return GetLChildIdx(idx);
    else
    {
        if (ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) < 0)
            return GetRChildIdx(idx);
        else
            return GetLChildIdx(idx);
    }
}
void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}
int HIsEmpty(Heap *ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}
void HInsert(Heap *ph, Data data)
{
    int idx = ph->numOfData + 1;
    while (idx != 1)
    {
        if (ph->comp(data, ph->heapArr[GetParentIdx(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        }
        else
            break;
    }
    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}
Data HDelete(Heap *ph)
{
    Data retData = ph->heapArr[1];
    Data lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;
    while (childIdx = GetHiPriChildIdx(ph, parentIdx))
    {
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}