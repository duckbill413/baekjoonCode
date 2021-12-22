//�߿䵵!
#include <stdio.h>

int main()
{
    char ch[51] = {0};
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int cnta = 0, cntb = 0;
        scanf("%s", ch);
        getchar();

        int flag = 1;
        for (int i = 0; ch[i] != 0; i++)
        {
            if (ch[i] == '(')
                cnta++;
            else if (ch[i] == ')')
                cntb++;

            if (cnta == 0 && cntb > 0)
            {
                flag = 0;
                break;
            }
            if (ch[i] == ')')
            {
                cnta--;
                cntb--;
            }
        }
        if (cnta != 0 || cntb != 0)
            flag = 0;

        if (flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}