#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 51
// Using MergeSort with Dynamic memory allocation
//�޸� ���� �Լ��� ���� ������� �ð� �ʰ� �߻�
void MergeTwoArea(char **arr, int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int sIdx = left;

    char **sortArr = (char **)malloc(sizeof(char *) * (right + 1));
    for (int i = 0; i <= right; i++)
        sortArr[i] = (char *)malloc(sizeof(char) * size);

    while (fIdx <= mid && rIdx <= right)
    {
        if (strlen(arr[fIdx]) > strlen(arr[rIdx]))
            strcpy(sortArr[sIdx], arr[rIdx++]);
        else if (strlen(arr[fIdx]) < strlen(arr[rIdx]))
            strcpy(sortArr[sIdx], arr[fIdx++]);
        else if (strlen(arr[fIdx]) == strlen(arr[rIdx]) && strcmp(arr[fIdx], arr[rIdx]) < 0)
            strcpy(sortArr[sIdx], arr[fIdx++]);
        else
            strcpy(sortArr[sIdx], arr[rIdx++]);

        sIdx++;
    }

    if (fIdx > mid)
    {
        for (int i = rIdx; i <= right; i++, sIdx++)
            strcpy(sortArr[sIdx], arr[i]);
    }
    else
    {
        for (int i = fIdx; i <= mid; i++, sIdx++)
            strcpy(sortArr[sIdx], arr[i]);
    }
    for (int i = left; i <= right; i++)
        strcpy(arr[i], sortArr[i]);

    for (int i = 0; i <= right; i++)
        free(sortArr[i]);
    free(sortArr);
}

void Mergesort(char **arr, int left, int right)
{
    int mid;
    if (left < right)
    {
        //�߰� ������ ����Ѵ�.
        mid = (left + right) / 2;

        //�ѷ� ������ ������ �����Ѵ�.
        Mergesort(arr, left, mid);
        Mergesort(arr, mid + 1, right);

        //���ĵ� �� �迭�� �����Ѵ�.
        MergeTwoArea(arr, left, mid, right);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    //�Է¹��� ���ڿ��� ����

    char **ch = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++)
    {
        ch[i] = (char *)malloc(sizeof(char) * size);
        scanf("%s", ch[i]);
        getchar();
    }

    Mergesort(ch, 0, N - 1); // Mergesort

    for (int i = 0; i < N; i++)
    {
        if (i > 0 && !strcmp(ch[i - 1], ch[i]))
            continue;
        printf("%s\n", ch[i]);
    }
    for (int i = 0; i < N; i++)
        free(ch[i]);
    free(ch);
}
/*
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
*/