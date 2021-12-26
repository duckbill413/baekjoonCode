#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    long long B;
    scanf("%d %d %lld", &N, &M, &B);

    int **he = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++)
        he[i] = (int *)calloc(M, sizeof(int));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &he[i][j]);

    for (int k = 0; k <= 256; k++)
    {
        int sum = 0, tmp = B;
    }
}