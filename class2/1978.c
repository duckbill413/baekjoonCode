//�߿䵵!!!
//�Ҽ� ����, �����佺�׳׽��� ü
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1001

// int primeNum[SIZE] = {0};
void Eratostheness(int *pnum);

int main()
{
    //�Էº�
    int N;
    scanf("%d", &N);
    int *num = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    // 1~1000������ ���� �Է� ����
    int primeNum[SIZE] = {0};
    Eratostheness(primeNum);
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) //�Ҽ� ����� ���캻��.
    {
        if (primeNum[i] == 0) // 0�̸� ����
            continue;
        for (int j = 0; j < N; j++)
        {
            if (primeNum[i] == num[j])
            {
                cnt++;
                break;
            }
        }
        if (cnt == N) //��� ����� �Ҽ��̸� �� �̻� ã�� �ʰ� ����
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