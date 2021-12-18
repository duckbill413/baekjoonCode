#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int size = 1004000;
    int prime_number[1004000] = {0};
    //에라토스테네스의 체_소수 찾기
    for (int i = 2; i < size; i++) // 1은 소수가 아니므로 2부터 시작
        prime_number[i] = i;
    for (int i = 2; i < size; i++)
    {
        if (prime_number == 0)
            continue;
        for (int j = i + i; j < size; j += i)
            prime_number[j] = 0;
    }
    for (int i = n; i < size; i++)
    {
        if (prime_number[i] == 0)
            continue; //소수가 아니면 생각하지 않는다.
        int num = i;
        int palin = 0;
        while (num != 0) // palin을 도출
        {
            palin = palin * 10 + num % 10;
            num /= 10;
        }
        if (i == palin)
        {
            printf("%d", i);
            break;
        }
    }
}