#include <stdio.h>
#include <math.h>
int palindrome(int n);

int main()
{
    int num;

    while (1)
    {
        scanf("%d", &num);
        if (num == 0)
            break;
        if (palindrome(num))
            printf("yes\n");
        else
            printf("no\n");
    }
}

int palindrome(int n)
{
    int k = n;
    int a = 0, b;
    int cnt = 0;
    int mid; //�߰� ��ġ�� �ڸ���
    // n�� �ڸ��� ���ϱ�
    while (k != 0)
    {
        cnt++;
        k /= 10;
    }
    if (cnt % 2 == 0) //¦��
    {
        mid = cnt / 2;
        b = n / pow(10, mid);
    }
    else //Ȧ��
    {
        mid = cnt / 2 + 1;
        b = n / pow(10, mid - 1);
    }
    k = n;
    for (int i = 0; i < mid; i++)
    {
        a = a * 10 + k % 10;
        k /= 10;
    }
    if (a == b)
        return 1;
    else
        return 0;
}