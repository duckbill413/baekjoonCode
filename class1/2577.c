#include <stdio.h>
#define cnt 3

int main()
{
    int num[cnt];
    int multi = 1;

    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &num[i]);
        multi *= num[i];
    }
    int num_cnt[10] = {0};

    while (multi != 0)
    {
        num_cnt[multi % 10]++;
        multi /= 10;
    }

    for (int i = 0; i < 10; i++)
        printf("%d\n", num_cnt[i]);
    return 0;
}