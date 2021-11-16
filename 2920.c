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
    for (int i = 1; i <= cnt; i++)
    {
        if (num[i - 1] == i)
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
        for (int i = 8; i >= 1; i--)
        {
            if (num[8 - i] == i)
                flag = 2;
            else
            {
                flag = 0;
                break;
            }
        }
    if (flag == 0)
        flag = 3;

    if (flag == 1)
        strcpy(result, "ascending");
    else if (flag == 2)
        strcpy(result, "descending");
    else if (flag == 3)
        strcpy(result, "mixed");

    printf("%s", result);
    return 0;
}