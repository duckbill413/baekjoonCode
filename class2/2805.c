//중요도!!!!!
//이분탐색
#include <stdio.h>
#include <stdlib.h>
#define TREE_HEIGHT 1000000000
long long maxHeight(long long *tree, int N, long long fi, int start, int end);

int main()
{
    int N;
    long long M;
    scanf("%d %lld", &N, &M);

    long long *tree = (long long *)malloc(sizeof(long long) * N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &tree[i]);

    printf("%lld", maxHeight(tree, N, M, 1, TREE_HEIGHT));
    free(tree);
}
long long maxHeight(long long *tree, int N, long long fi, int start, int end)
{
    if (start > end)
        return end;
    long long mid = (start + end) / 2;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (tree[i] - mid > 0)
            sum += (tree[i] - mid);
    }
    if (sum < fi)
        return maxHeight(tree, N, fi, start, mid - 1);
    else
        return maxHeight(tree, N, fi, mid + 1, end);
}