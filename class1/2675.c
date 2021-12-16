#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
    {
        int cnt;
        char tmp[21];
        scanf("%d %s", &cnt, tmp);
        getchar();
        for (char *ptmp = tmp; ptmp < tmp + strlen(tmp); ptmp++)
        {
            for (int j = 0; j < cnt; j++)
                printf("%c", *ptmp);
        }
        printf("\n");
    }

    return 0;
}