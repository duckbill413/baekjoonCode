//�߿䵵!!!
//����Ʈ, �̺�Ž��
#include <stdio.h>
#include <stdlib.h>

int compare(const void *left, const void *right);
int boolFind(int *pnum, int fi, int start, int end);

int main()
{
    // N �ڿ��� �Է�
    int N;
    scanf("%d", &N);
    int *Nnum = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &Nnum[i]);
    // M �ڿ��� �Է�
    int M;
    scanf("%d", &M);
    int *Mnum = (int *)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++)
        scanf("%d", &Mnum[i]);

    qsort(Nnum, N, sizeof(int), compare); // N �ڿ����� �������� ����

    for (int i = 0; i < M; i++)
    {
        printf("%d\n", boolFind(Nnum, Mnum[i], 0, N - 1));
    }

    free(Nnum);
    free(Mnum);
}
int compare(const void *left, const void *right)
{
    int a = *(int *)left;
    int b = *(int *)right;

    if (a < b) // �������� ����
        return -1;
    else
        return 1;
}
int boolFind(int *pnum, int fi, int start, int end)
{
    if (start > end)
        return 0;
    int mid = (start + end) / 2;
    if (pnum[mid] == fi)
        return 1;

    if (pnum[mid] > fi)
        return boolFind(pnum, fi, start, mid - 1);
    else
        return boolFind(pnum, fi, mid + 1, end);
}

/*
test case)
5
4 1 5 2 3
5
1 3 7 9 5

result)
1
1
0
0
1
*/