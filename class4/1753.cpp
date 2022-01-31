// 1753 최단경로
// 다익스트라
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 1e9
using namespace std;
typedef pair<int, int> P;
struct compare
{
    bool operator()(P a, P b)
    {
        return a.second > b.second;
    }
};

void Dijkstra(int K, vector<vector<P>> &MAP, vector<int> &Dist);
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V, E;
    cin >> V >> E;
    int K, u, v, w;
    vector<vector<P>> MAP(V + 1, vector<P>());
    vector<int> Dist(V + 1, INF);
    cin >> K;
    for (int i = 1; i <= E; i++)
    {
        cin >> u >> v >> w;
        MAP[u].push_back({v, w});
    }

    Dijkstra(K, MAP, Dist);

    for (int i = 1; i <= V; i++)
    {
        if (Dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << Dist[i] << '\n';
    }
}
void Dijkstra(int K, vector<vector<P>> &MAP, vector<int> &Dist)
{
    priority_queue<P, vector<P>, compare> pq;
    pq.push(make_pair(K, 0));
    Dist[K] = 0;

    while (!pq.empty())
    {
        P cur = pq.top();
        pq.pop();

        for (int i = 0; i < MAP[cur.first].size(); i++)
        {
            P next = MAP[cur.first][i];
            int cost = cur.second + next.second;
            if (cost < Dist[next.first])
            {
                Dist[next.first] = cost;
                pq.push(make_pair(next.first, cost));
            }
        }
    }
}