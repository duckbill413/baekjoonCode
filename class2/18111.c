#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int N, M;
    long long B;
    scanf("%d %d %lld", &N, &M, &B);

    int **block = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++)
        block[i] = (int *)calloc(M, sizeof(int));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &block[i][j]);

    int Time = INT_MAX, height;
    // 0층 ~ 256층
    for (int k = 0; k <= 256; k++)
    {
        int time = 0, tmp = B;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (block[i][j] < k) // block 넣기 +1초
                {                    //기준보다 낮을 경우
                    time += k - block[i][j];
                    tmp -= k - block[i][j];
                }
                else if (block[i][j] > k) // block 빼서 인벤토리에 넣기 +2초
                {                         //기준보다 높을 경우
                    time += (block[i][j] - k) * 2;
                    tmp += (block[i][j] - k);
                }
            }
        }
        if (tmp >= 0) //인벤토리 안의 블럭이 음수가 아닐 경우
        {
            if (time <= Time) //높이가 높은 것이 우선이므로 '=' 포함
            {
                Time = time;
                height = k;
            }
        }
    }
    printf("%d %d", Time, height);
    for (int i = 0; i < N; i++)
        free(block[i]);
    free(block);
}