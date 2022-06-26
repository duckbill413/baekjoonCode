// 1005 ACM Craft 위상정렬
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;
int T, N, K;
int target;
typedef pair<int, int> P;
vector<int> edge[MAX];
vector<P> cost(MAX, {0, 0});
int dp[MAX];

void TopologicalSort()
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (cost[i].first == 0)
        {
            q.push(i);
            dp[i] = cost[i].second;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < edge[cur].size(); i++)
        {
            int next = edge[cur][i];
            dp[next] = max(dp[next], dp[cur] + cost[next].second);
            if (--cost[next].first == 0)
                q.push(next);
        }
    }

    cout << dp[target] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> cost[i].second;

        for (int i = 0; i < K; i++)
        {
            int s, e;
            cin >> s >> e;
            edge[s].push_back(e);
            cost[e].first++;
        }
        cin >> target;
        TopologicalSort();

        memset(edge, 0, sizeof(edge));
        memset(dp, 0, sizeof(dp));
        fill(&cost[0].first, &cost[sizeof(cost)].second, 0);
    }

    return 0;
}