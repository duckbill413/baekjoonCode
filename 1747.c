#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int size = 1004000;
    int prime_number[1004000] = {0};
    //�����佺�׳׽��� ü_�Ҽ� ã��
    for (int i = 2; i < size; i++) // 1�� �Ҽ��� �ƴϹǷ� 2���� ����
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
            continue; //�Ҽ��� �ƴϸ� �������� �ʴ´�.
        int num = i;
        int palin = 0;
        while (num != 0) // palin�� ����
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