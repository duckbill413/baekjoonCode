//선택 정렬
#include <stdio.h>

int selection_sort(int num[], int size, int cnt, int *left, int *right);

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int num[500000];
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    int left, right;
    if (selection_sort(num, N, K, &left, &right))
        printf("%d %d", left, right);
    else
        printf("-1");
}

int selection_sort(int num[], int size, int cnt, int *left, int *right)
{
    int tmpCnt = 0;
    for (int i = size - 1; i > 0; i--)
    {
        int maxIdx = i;
        for (int j = 0; j < i; j++)
        {
            if (num[j] > num[maxIdx])
            {
                maxIdx = j;
            }
        }
        if (maxIdx != i)
        {
            int tmp = num[maxIdx];
            num[maxIdx] = num[i];
            num[i] = tmp;
            *left = num[maxIdx];
            *right = num[i];
            tmpCnt++;
        }
        if (tmpCnt == cnt)
            return 1;
    }
    return 0;
}