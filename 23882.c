//선택 정렬
#include <stdio.h>

int selection_sort(int num[], int size, int cnt);

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int num[500000];
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    if (selection_sort(num, N, K))
        for (int i = 0; i < N; i++)
            printf("%d ", num[i]);
    else
        printf("-1");
}

int selection_sort(int num[], int size, int cnt)
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
            tmpCnt++;
        }
        if (tmpCnt == cnt)
            return 1;
    }
    return 0;
}