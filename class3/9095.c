//중요도!!!
//다이나믹 프로그래밍
#include <stdio.h>
#define min(a, b) a > b ? b : a
void getCnt(int n, int *cnt);

int main()
{
    int T;
    scanf("%d", &T);
    int n;
    int cnt[11] = {0};
    cnt[1] = 1;
    cnt[2] = 2;
    cnt[3] = 4;
    while (T--)
    {
        scanf("%d", &n);
        getCnt(n, cnt);
        printf("%d\n", cnt[n]);
    }
}
void getCnt(int n, int *cnt)
{
    for (int i = 4; i <= n; i++)
        cnt[i] = cnt[i - 1] + cnt[i - 2] + cnt[i - 3];
}