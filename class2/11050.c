//중요도!
//이항계수
#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int upper = 1, lower = 1;
    for (int i = N; i > N - K; i--)
        upper *= i;
    for (int i = 1; i <= K; i++)
        lower *= i;
    printf("%d", upper / lower);
}