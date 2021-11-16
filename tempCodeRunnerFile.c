#include <stdio.h>
#include <string.h>
#define cnt 8
int main()
{
    char result[20];
    int num[cnt];
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &num[i]);
    }

    int flag = 0;
    for (int i = 0; i < cnt - 1; i++)
    {
        if (num[i] < num[i + 1] && flag == 0)
            flag = 1;
        if (num[i] > num[i + 1] && flag == 0)
            flag = 2;
        if (num[i] < num[i + 1] && flag == 2)
            flag = 3;
        if (num[i] > num[i + 1] && flag == 1)
            flag = 3;
    }

    if (flag == 1)
        strcpy(result, "ascending");
    else if (flag == 2)
        strcpy(result, "desending");
    else if (flag == 3)
        strcpy(result, "mixed");

    printf("%s", result);
    return 0;
}