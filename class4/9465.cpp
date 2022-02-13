// 9465 ½ºÆ¼Ä¿
#include <iostream>
#include <vector>
#include <queue>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

vector<vector<int>> Cost(vector<vector<int>> &table)
{
    int n = table[0].size();
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = table[0][0];
    dp[1][0] = table[1][0];
    if (n > 1)
    {
        dp[0][1] = table[0][1] + table[1][0];
        dp[1][1] = table[1][1] + table[0][0];
    }
    for (int i = 2; i < n; i++)
    {
        dp[0][i] = table[0][i] + MAX(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = table[1][i] + MAX(dp[0][i - 1], dp[0][i - 2]);
    }

    return dp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<vector<int>> table(2, vector<int>(n, 0));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> table[i][j];

        vector<vector<int>> DP = Cost(table);
        cout << MAX(DP[0][n - 1], DP[1][n - 1]) << '\n';
    }
}