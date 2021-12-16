#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Using quickSort with Dynamic memory allocation
// Using struct
// result: 성공
typedef struct _word
{
    char str[51];
    int len;
} Word;

int compare(const void *left, const void *right)
{
    Word *a = (Word *)left;
    Word *b = (Word *)right;

    if (a->len < b->len)
        return -1;
    else if (a->len > b->len)
        return 1;
    else
    {
        if (strcmp(a->str, b->str) < 0)
            return -1;
        else
            return 1;
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    //입력받을 문자열의 개수

    Word *word = (Word *)malloc(sizeof(Word) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", word[i].str);
        word[i].len = strlen(word[i].str);
        getchar();
    }

    qsort(word, N, sizeof(word[0]), compare);

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