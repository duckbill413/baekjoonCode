// 1446 지름길
// 중요도!!!!
#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, D;
    cin >> N >> D;
    vector<int> Map(D + 1, INF);
    vector<pair<int, int>> Pass[10001];
    int s, e, d;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> e >> d;
        Pass[e].push_back({s, d});
    }
    Map[0] = 0;
    for (int i = 1; i <= D; i++)
    {
        if (Pass[i].size() == 0)
            Map[i] = Map[i - 1] + 1;
        else
        {
            for (auto j : Pass[i])
                Map[i] = min(Map[i], min(Map[i - 1] + 1, Map[j.first] + j.second));
        }
    }

    cout << Map[D];
    return 0;
}