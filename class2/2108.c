#include <stdio.h>
#include <stdlib.h>

// int compare(const void *left, const void *right)
// {
//     int a = *(int *)left;
//     int b = *(int *)right;
//     if (a > b)
//         return 1;
//     else
//         return -1;
// }
void MergeTwoArea(int *num, int left, int mid, int right);
void Mergesort(int *num, int left, int right);
int Mode(int *num, int N);
int main()
{
    int N;
    scanf("%d", &N);
    int *num = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    //산술 평균
    double avg = 0.0;
    for (int i = 0; i < N; i++)
        avg += num[i];
    avg /= N;
    printf("%.lf\n", avg);

    //중앙값
    // qsort(num, N, sizeof(int), compare);//quicksort
    Mergesort(num, 0, N - 1); // Mergesort
    int mid = N / 2;
    printf("%d\n", num[mid]);

    //최빈값
    printf("%d\n", Mode(num, N));

    //범위(최댓값-최솟값);
    int len = num[N - 1] - num[0];
    printf("%d", len);
}

void MergeTwoArea(int *num, int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int sIdx = left;

    int *sortNum = (int *)malloc(sizeof(int) * (right + 1));

    while (fIdx <= mid && rIdx <= right)
    {
        if (num[fIdx] > num[rIdx])
            sortNum[sIdx] = num[rIdx++];
        else
            sortNum[sIdx] = num[fIdx++];
        sIdx++;
    }

    if (fIdx > mid)
    {
        for (int i = rIdx; i <= right; i++, sIdx++)
            sortNum[sIdx] = num[i];
    }
    else
    {
        for (int i = fIdx; i <= mid; i++, sIdx++)
            sortNum[sIdx] = num[i];
    }
    for (int i = left; i <= right; i++)
        num[i] = sortNum[i];

    free(sortNum);
}

void Mergesort(int *num, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        Mergesort(num, left, mid);
        Mergesort(num, mid + 1, right);
        MergeTwoArea(num, left, mid, right);
    }
}

int Mode(int *num, int N)
{
    //절댓값이 4000이하의 수이다.
    int num_cnt[8001] = {0};
    int idx, max_cnt = 0, cnt = 0;
    for (int i = 0; i < N; i++) //숫자의 빈도 및 최대 빈도 구하기
    {
        // idx = 0 => -4000 idx = 8000 => 4000
        idx = num[i] + 4000; // idx로 변환
        num_cnt[idx]++;
        if (num_cnt[idx] > max_cnt)
            max_cnt = num_cnt[idx];
    }
    for (int i = 0; i < 8001; i++)
    {
        if (num_cnt[i] == 0)
            continue;

        // 0=>-4000 이므로 아래 부터 탐색해서 두번째 max인 수가 두번째 최솟값이다.
        // 모든 숫자 탐색시 처음 max 위치의 idx가 최솟값이다.
        if (num_cnt[i] == max_cnt)
        {
            if (cnt == 0)
            {
                idx = i;
                cnt++;
            }
            else if (cnt == 1)
            {
                idx = i;
                break;
            }
        }
    }
    return idx - 4000;
}