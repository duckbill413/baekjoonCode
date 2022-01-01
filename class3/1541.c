//�߿䵵!!
#include <stdio.h>
#include <string.h>

int main()
{
    char str[120];
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = 0;
    int minusFlag = 0;
    for (char *pstr = str; pstr <= str + strlen(str); pstr++)
    {
        if (pstr == str + strlen(str) && minusFlag > 0)
        {
            *pstr = ')';
            *(pstr + 1) = 0;
            minusFlag--;
        }
        if (*pstr == '-' && minusFlag == 0)
        {
            char tmp[100];
            strcpy(tmp, pstr + 1);
            *(pstr + 1) = '(';
            strcpy(pstr + 2, tmp);

            minusFlag++;
        }
        else if (*pstr == '-' && minusFlag > 0)
        {
            char tmp[100];
            strcpy(tmp, pstr);
            *pstr = ')';
            strcpy(pstr + 1, tmp);
            minusFlag--;
        }
    }

    // printf("%s\n", str);
    int total = 0;
    int sum = 0;
    int tmp = 0;

    int flag = 0;
    for (char *pstr = str; pstr <= str + strlen(str); pstr++)
    {
        if (*pstr >= '0' && *pstr <= '9')
        {
            tmp = tmp * 10 + (*pstr - '0');
        }
        else
        {
            sum += tmp;
            tmp = 0;
        }

        if (*pstr == '(' || *pstr == ')' || pstr == str + strlen(str))
        {
            if (flag == 0)
            {
                total += sum;
                sum = 0;
            }
            else
            {
                total -= sum;
                sum = 0;
            }
            if (*(pstr - 1) == '-')
                flag = 1;
            else if (*(pstr - 1) == '+')
                flag = 0;
        }
    }
    printf("%d", total);
}