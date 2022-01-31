// 1504 특정한 최단 경로
// 중요도!!!
// 다익스트라 알고리즘, 우선순위 큐
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
void DistInit(vector<int> &Dist);
void Dijkstra(int start, vector<vector<P>> &pass, vector<int> &Dist);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, E;
    cin >> N >> E;
    vector<vector<P>> pass(N + 1, vector<P>());
    vector<int> Dist(N + 1, INF);

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pass[a].push_back({b, c});
        pass[b].push_back({a, c});
    }
    int v1, v2; //경로상 정점 두개
    cin >> v1 >> v2;

    long long StoV1 = 0, StoV2 = 0, V1toV2 = 0, V1toN = 0, V2toN = 0;
    Dijkstra(v1, pass, Dist);
    StoV1 = Dist[1];
    V1toV2 = Dist[v2];
    V1toN = Dist[N];
    
    DistInit(Dist);
    Dijkstra(v2, pass, Dist);
    StoV2 = Dist[1];
    V2toN = Dist[N];

    long long result = INF;
    result = min(result, (StoV1 + V1toV2 + V2toN));
    result = min(result, (StoV2 + V1toV2 + V1toN));
    if (result == INF || V1toV2 == INF)
        cout << "-1";
    else
        cout << result;
}
void DistInit(vector<int> &Dist)
{
    for (int i = 0; i < Dist.size(); i++)
        Dist[i] = INF;
}

void Dijkstra(int start, vector<vector<P>> &pass, vector<int> &Dist)
{
    priority_queue<P, vector<P>, compare> pq;
    pq.push({start, 0});
    Dist[start] = 0;

    while (!pq.empty())
    {
        P cur = pq.top();
        pq.pop();

        for (int i = 0; i < pass[cur.first].size(); i++)
        {
            P next = pass[cur.first][i];
            int cost = cur.second + next.second;
            if (cost < Dist[next.first])
            {
                Dist[next.first] = cost;
                pq.push({next.first, cost});
            }
        }
    }
}