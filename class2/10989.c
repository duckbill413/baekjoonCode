//중요도!!!!!
// counting sort
//시간제한은 5초로 넉넉하나 메모리가 8MB 제한인데에 비해 입력개수가 매우 크다.
//상대적으로 자연수의 입력 범위는 매우 적다.
#include <stdio.h>
#define MAX_VAL 10001

int main()
{
    int N;
    scanf("%d", &N);

    int cnt[MAX_VAL] = {0};
    for (int i = 0; i < N; i++)
    {
        int idx;
        scanf("%d", &idx);
        cnt[idx]++;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (cnt[i] == 0)
            continue;

        for (int j = 0; j < cnt[i]; j++)
            printf("%d\n", i);
    }
}
