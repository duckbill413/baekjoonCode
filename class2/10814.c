//�߿䵵!!!!!
// Mergesort
#include <stdio.h>
#include <stdlib.h>

typedef struct member
{
    int age;
    char name[101];
} Member;

void MergeTwoArea(Member *mem, int left, int mid, int right);
void Mergesort(Member *mem, int left, int right);

int main()
{
    int N;
    scanf("%d", &N);

    Member *mem = (Member *)malloc(sizeof(Member) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &mem[i].age, mem[i].name);
        getchar();
    }
    Mergesort(mem, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%d %s\n", mem[i].age, mem[i].name);
    free(mem);
}

void Mergesort(Member *mem, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        Mergesort(mem, left, mid);
        Mergesort(mem, mid + 1, right);
        MergeTwoArea(mem, left, mid, right);
    }
}

void MergeTwoArea(Member *mem, int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int sIdx = left;

    Member *sortMem = (Member *)malloc(sizeof(Member) * (right + 1));

    while (fIdx <= mid && rIdx <= right)
    {
        if (mem[fIdx].age > mem[rIdx].age)
            sortMem[sIdx++] = mem[rIdx++];
        else if (mem[fIdx].age <= mem[rIdx].age)
            sortMem[sIdx++] = mem[fIdx++];
    }

    if (fIdx > mid)
    {
        for (int i = rIdx; i <= right; i++, sIdx++)
            sortMem[sIdx] = mem[i];
    }
    else
    {
        for (int i = fIdx; i <= mid; i++, sIdx++)
            sortMem[sIdx] = mem[i];
    }

    for (int i = left; i <= right; i++)
        mem[i] = sortMem[i];
    free(sortMem);
}