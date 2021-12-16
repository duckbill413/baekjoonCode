#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Using MergeSort with Dynamic memory allocation
// Using struct
// result: ����
typedef struct _word
{
    char str[51];
    int len;
} Word;

void MergeTwoArea(Word *word, int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int sIdx = left;

    Word *sortWord = (Word *)malloc(sizeof(Word) * (right + 1));

    while (fIdx <= mid && rIdx <= right)
    {
        if (word[fIdx].len > word[rIdx].len)
            sortWord[sIdx] = word[rIdx++];
        else if (word[fIdx].len < word[rIdx].len)
            sortWord[sIdx] = word[fIdx++];
        else
        {
            if (strcmp(word[fIdx].str, word[rIdx].str) < 0)
                sortWord[sIdx] = word[fIdx++];
            else
                sortWord[sIdx] = word[rIdx++];
        }
        sIdx++;
    }

    if (fIdx > mid)
    {
        for (int i = rIdx; i <= right; i++, sIdx++)
            sortWord[sIdx] = word[i];
    }
    else
    {
        for (int i = fIdx; i <= mid; i++, sIdx++)
            sortWord[sIdx] = word[i];
    }
    for (int i = left; i <= right; i++)
        word[i] = sortWord[i];

    free(sortWord);
}

void Mergesort(Word *word, int left, int right)
{
    int mid;
    if (left < right)
    {
        //�߰� ������ ����Ѵ�.
        mid = (left + right) / 2;

        //�ѷ� ������ ������ �����Ѵ�.
        Mergesort(word, left, mid);
        Mergesort(word, mid + 1, right);

        //���ĵ� �� �迭�� �����Ѵ�.
        MergeTwoArea(word, left, mid, right);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    //�Է¹��� ���ڿ��� ����

    Word *word = (Word *)malloc(sizeof(Word) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", word[i].str);
        word[i].len = strlen(word[i].str);
        getchar();
    }

    Mergesort(word, 0, N - 1); // Mergesort

    for (int i = 0; i < N; i++)
    {
        if (i > 0 && !strcmp(word[i - 1].str, word[i].str))
            continue;
        printf("%s\n", word[i].str);
    }
    free(word);
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