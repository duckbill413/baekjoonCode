//중요도!!!!
//해쉬, 이분탐색, 퀵소트
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pocketmon
{
    char name[21];
    int idx;
} Pocketmon;

int compare(const void *left, const void *right);
int binSearch(char *fi, Pocketmon *po, int start, int end);
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();

    Pocketmon *poName = (Pocketmon *)malloc(sizeof(Pocketmon) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", poName[i].name);
        getchar();
        poName[i].idx = i + 1;
    }
    Pocketmon *poIdx = (Pocketmon *)malloc(sizeof(Pocketmon) * N);
    for (int i = 0; i < N; i++)
        poIdx[i] = poName[i];

    qsort((void *)poName, N, sizeof(poName[0]), compare);

    char fi[21];
    while (M--)
    {
        scanf("%s", fi);
        getchar();
        int idx = 0;
        if (fi[0] >= '0' && fi[0] <= '9')
        {
            for (char *p = fi; p < fi + strlen(fi); p++)
            {
                idx = idx * 10 + (*p - '0');
            }
            printf("%s\n", poIdx[idx - 1].name);
        }
        else
        {
            idx = binSearch(fi, poName, 0, N - 1);
            printf("%d\n", idx);
        }
    }

    free(poIdx);
    free(poName);
}

int compare(const void *left, const void *right)
{
    Pocketmon a = *(Pocketmon *)left;
    Pocketmon b = *(Pocketmon *)right;
    // printf("cmp: %s %s\n", a.name, b.name);
    if (strcmp(a.name, b.name) > 0)
        return 1;
    else
        return -1;
}
int binSearch(char *fi, Pocketmon *po, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    // printf("cmp: %s %d\n", po[mid].name, po[mid].idx);
    if (strcmp(fi, po[mid].name) > 0)
        return binSearch(fi, po, mid + 1, end);
    else if (strcmp(fi, po[mid].name) < 0)
        return binSearch(fi, po, start, mid - 1);
    else
        return po[mid].idx;
}