#include <stdio.h>
#define mod 1000000000

int dp[101][10][1 << 10]; // 최대 100자리, 현재 자리수의 수, 사용한 숫자 체크

int main()
{
    int N;
    scanf("%d", &N);

    int full = (1 << 10) - 1; // 모든 수를 지나는 경우
    for (int i = 1; i <= 9; i++)
        dp[1][i][1 << i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= full; k++)
            {
                if (j == 0)
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
                else
                {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
                }
            }
        }
    }
    int ans;
    for (int i = 0; i <= 9; i++)
        ans = (ans + dp[N][i][full]) % mod;

    printf("%d", ans);
    return 0;
}