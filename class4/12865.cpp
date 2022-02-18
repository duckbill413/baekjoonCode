// 12865 ����� �賶
// knapsack �˰���
// ���Կ� ��ġ�� 2���� �迭�� ���� ����
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        int w, v;
        cin >> w >> v;
        for (int j = 1; j <= K; j++)
        {
            if (w <= j)
                dp[i][j] = max(dp[i - 1][j], v + dp[i - 1][j - w]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][K];
    return 0;
}