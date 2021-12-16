#include <stdio.h>
#include <string.h>

int main()
{
    char ch[102];
    fgets(ch, sizeof(ch), stdin);
    ch[strlen(ch) - 1] = 0;

    for (char i = 'a'; i <= 'z'; i++)
    {
        int found = 0;
        for (char *pch = ch; pch < ch + strlen(ch); pch++)
        {
            if (*pch == i)
            {
                printf("%d ", pch - ch);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("-1 ");
    }
}
