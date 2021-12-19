//중요도!!!
//소수 판정, 에라토스테네스의 체
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1001

// int primeNum[SIZE] = {0};
void Eratostheness(int *pnum);

int main()
{
    //입력부
    int N;
    scanf("%d", &N);
    int *num = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    // 1~1000까지의 정수 입력 변수
    int primeNum[SIZE] = {0};
    Eratostheness(primeNum);
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) //소수 멤버를 살펴본다.
    {
        if (primeNum[i] == 0) // 0이면 제외
            continue;
        for (int j = 0; j < N; j++)
        {
            if (primeNum[i] == num[j])
            {
                cnt++;
                break;
            }
        }
        if (cnt == N) //모든 멤버가 소수이면 더 이상 찾지 않고 종료
            break;
    }

    printf("%d", cnt);
    free(num);
}

void Eratostheness(int *pnum)
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