#include <stdio.h>

int main()
{
    int num[3];
    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (num[j] > num[j + 1])
            {
                int tmp = num[j + 1];
                num[j + 1] = num[j];
                num[j] = tmp;
            }
        }
    }

    printf("%d %d %d", num[0], num[1], num[2]);
    return 0;
}