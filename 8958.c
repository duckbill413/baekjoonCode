#include <stdio.h>
#include <string.h>
int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
    {
        char tmp[100];
        fgets(tmp, sizeof(tmp), stdin);
        int score = 0;
        int cnt = 1;
        for (char *ptmp = tmp; *ptmp != 0; ptmp++)
        {
            if (*ptmp == 'O')
            {
                score += cnt;
                cnt++;
            }
            else
                cnt = 1;
        }
        printf("%d\n", score);
    }

    return 0;
}