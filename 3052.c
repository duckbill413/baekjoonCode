#include <stdio.h>
#define cnt 10
#define divide 42

int main()
{
    int num[cnt];
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &num[i]);
    }

    int number[divide] = {0};
    for (int i = 0; i < cnt; i++)
    {
        int result = num[i] % divide;
        number[result] = 1;
    }
    int num_cnt = 0;
    for (int j = 0; j < divide; j++)
    {
        if (number[j] == 1)
            num_cnt++;
    }
    printf("%d", num_cnt);
    return 0;
}