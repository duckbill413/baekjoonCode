#include <stdio.h>

int main()
{
    int T, M, N, K;
    int X[50] = {0}, Y[50] = {0};
    scanf("%d", &T);
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; i++)
        scanf("%d %d", &X[i], &Y[i]);
}