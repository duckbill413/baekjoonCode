#include <stdio.h>
#include <string.h>
int main()
{
    char ch[1000001];
    fgets(ch, sizeof(ch), stdin);
    ch[strlen(ch) - 1] = 0;

    int max = 0;
    char max_ch;

    for (char i = 'A'; i <= 'Z'; i++)
    {
        int cnt = 0;
        for (char *pch = ch; pch < ch + strlen(ch); pch++)
        {
            if (*pch == i || *pch == (i + ('a' - 'A')))
                cnt++;
        }
        if (cnt >= max)
        {
            if (cnt == max)
                max_ch = '?';
            else
                max_ch = i;
            max = cnt;
        }
    }
    printf("%c", max_ch);
    return 0;
}