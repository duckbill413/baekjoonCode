//중요도!!!!!
// binary search, Lower:Upper bound
#include <stdio.h>
#include <stdlib.h>

int compare(const void *left, const void *right);
int Ubound(int *num, int fi, int start, int end);
int Lbound(int *num, int fi, int start, int end);
int main()
{
    //입력부
    int N, M;
    scanf("%d", &N);

    int *Ncard = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &Ncard[i]);
    scanf("%d", &M);

    int *Mcard = (int *)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++)
        scanf("%d", &Mcard[i]);

    int *cnt = (int *)calloc(M, sizeof(int)); //개수 카운트 변수

    // N member sorting
    qsort(Ncard, N, sizeof(int), compare);

    for (int i = 0; i < M; i++)
        cnt[i] = Ubound(Ncard, Mcard[i], 0, N) - Lbound(Ncard, Mcard[i], 0, N);

    for (int i = 0; i < M; i++)
        printf("%d ", cnt[i]);

    free(Ncard);
    free(Mcard);
    free(cnt);
}
int compare(const void *left, const void *right)
{
    int a = *(int *)left;
    int b = *(int *)right;
    if (a > b)
        return 1;
    else
        return -1;
}
int Ubound(int *num, int fi, int start, int end)
{
    while (start < end)
    {
        int mid = (start + end) / 2;

        if (num[mid] <= fi)
            start = mid + 1;
        else
            end = mid;
    }
    return end + 1;
}
int Lbound(int *num, int fi, int start, int end)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (num[mid] < fi)
            start = mid + 1;
        else
            end = mid;
    }
    return end + 1;
}