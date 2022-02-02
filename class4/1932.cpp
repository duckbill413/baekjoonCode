// 1932 Á¤¼ö »ï°¢Çü
#include <iostream>
#include <vector>
#include <algorithm>
#define TREE_SIZE 501
using namespace std;

int BIG(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int SIZE = 0;
    for (int i = 1; i <= N; i++)
        SIZE += i;

    vector<int> tree(SIZE, 0);
    for (int i = 0; i < SIZE; i++)
        cin >> tree[i];

    vector<vector<int>> dp(N + 1, vector<int>());
    dp[1].push_back(tree[0]);
    int R = 1;
    int point = 1;
    for (int i = 2; i <= N; i++)
    {
        int K = 0;
        for (int j = point; j < point + R + 1; j++)
        {
            if (j == point)
                dp[i].push_back(dp[i - 1][0] + tree[j]);
            else if (j == point + R)
                dp[i].push_back(dp[i - 1][R - 1] + tree[j]);
            else
            {
                dp[i].push_back(BIG(dp[i - 1][K] + tree[j], dp[i - 1][K + 1] + tree[j]));
                K++;
            }
        }
        R += 1;
        point += i;
    }

    int res = 0;
    for (int i = 0; i < dp[N].size(); i++)
        if (res < dp[N][i])
            res = dp[N][i];

    cout << res;
}