//�߿䵵!!!
//���� : ���� ���е� / ū �� ����
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int mul = 1;

    int cnt = 0;
    for (int i = 2; i <= N; i++)
    {
        mul *= i;

        if (mul % 10 == 0)
        {
            while (1)
            {
                mul /= 10;
                cnt++;
                if (mul % 10 != 0)
                    break;
            }
        }
        mul %= 1000000;
    }

    printf("%d\n", cnt);
}