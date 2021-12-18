//중요도!!!
//에라토스테네스의 체 - 소수 찾기
#include <stdio.h>
#define SIZE 1000001
void Eratosthenes(int *pnum);

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);

    int primeNum[SIZE] = {0};
    Eratosthenes(primeNum);

    for (int i = M; i <= N; i++)
        if (primeNum[i] != 0)
            printf("%d\n", primeNum[i]);
}

void Eratosthenes(int *pnum)
{
    for (int i = 2; i < SIZE; i++)
        pnum[i] = i;

    for (int i = 2; i < SIZE; i++)
    {
        if (pnum[i] == 0)
            continue;
        for (int j = i + i; j < SIZE; j += i)
            pnum[j] = 0;
    }
}