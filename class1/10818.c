#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int *num = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
        scanf("%d", num + i);

    int small = INT_MAX;
    int big = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        if (small > num[i])
            small = num[i];
        if (big < num[i])
            big = num[i];
    }
    printf("%d %d", small, big);
    free(num);
}