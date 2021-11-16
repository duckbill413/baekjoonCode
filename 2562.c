#include <stdio.h>
#define cnt 9
int main()
{
    int max = 0;
    int pmax = 0;

    int num[cnt] = {0};
    for (int i = 0; i < cnt; i++)
        scanf("%d", &num[i]);

    for (int i = 0; i < cnt; i++)
    {
        if (max < num[i])
        {
            max = num[i];
            pmax = i;
        }
    }

    printf("%d\n%d", num[pmax], pmax + 1);
    return 0;
}