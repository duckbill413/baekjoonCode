//중요도!!!!!
//이분탐색
#include <stdio.h>
#include <stdlib.h>

long long correctLen(long long *len, int K, int N, long long start, long long end);

int main()
{
    int K, N;
    scanf("%d %d", &K, &N);
    long long *len = (long long *)malloc(sizeof(long long) * K);
    for (int i = 0; i < K; i++)
        scanf("%lld", &len[i]);
    printf("%lld", correctLen(len, K, N, 1, (long long)1 << 32));
    free(len);
}

long long correctLen(long long *len, int K, int N, long long start, long long end)
{
    if (start > end)
        return end;
    long long mid = (start + end) / 2;
    int cnt = 0;
    for (int i = 0; i < K; i++)
        cnt += len[i] / mid;

    if (cnt < N)
        return correctLen(len, K, N, start, mid - 1);
    else
        return correctLen(len, K, N, mid + 1, end);
}

/*
test case)
4 11
802
743
457
539

result)
200
*/