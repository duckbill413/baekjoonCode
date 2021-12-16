#include <stdio.h>
#include <string.h>

int main()
{
    char tmp[1000001];
    fgets(tmp, sizeof(tmp), stdin);
    tmp[strlen(tmp) - 1] = 0;
    int size = 0, cnt = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == 0)
        {
            if (size > 0)
                cnt++;
            size = -1;
        }
        size++;
    }
    printf("%d", cnt);
}