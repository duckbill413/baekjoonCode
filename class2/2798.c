//중요도!
//브루트포스 알고리즘
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int *card = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &card[i]);

    int close;
    int closeSum;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int sum = card[i] + card[j] + card[k];
                //조건: M과 가장 가까운가, M을 넘지 않는가
                if ((M - sum) < close && M - sum >= 0 || (i == 0 && j == 1 && k == 2))
                {
                    close = abs(sum - M);
                    closeSum = sum;
                }
            }
        }
    }

    printf("%d", closeSum);
    free(card);
}