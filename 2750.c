#include <stdio.h>
//수 정렬하기(오름차순)
//버블정렬
int main()
{
    int cnt;
    scanf("%d", &cnt);
    int num[1000] = {0};
    for (int i = 0; i < cnt; i++)
        scanf("%d", &num[i]);

    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = 0; j < cnt - i - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                int tmp = num[j + 1];
                num[j + 1] = num[j];
                num[j] = tmp;
            }
        }
    }

    for (int i = 0; i < cnt; i++)
        printf("%d\n", num[i]);

    return 0;
}