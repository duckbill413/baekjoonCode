#include <stdio.h>

int main()
{
    while (1)
    {
        int num[3];
        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        if (num[0] == 0 && num[1] == 0 && num[2] == 0)
            break;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2 - i; j++)
            {
                if (num[j] < num[j + 1])
                {
                    int tmp = num[j + 1];
                    num[j + 1] = num[j];
                    num[j] = tmp;
                }
            }
        if (num[0] * num[0] == (num[1] * num[1] + num[2] * num[2]))
            printf("right\n");
        else
            printf("wrong\n");
    }
}