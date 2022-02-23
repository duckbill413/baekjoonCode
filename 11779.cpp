// 11779 최소 비용 구하기2
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
typedef pair<int, int> P;
struct compare
{
    bool operator()(P a, P b)
    {
        return a.second > b.second;
    }
};
void Dijkstra(int start, vector<vector<P>> &Map, vector<int> &Dist, vector<vector<int>> &Pass);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, S, E;
    cin >> N >> M;
    vector<vector<P>> Map(N + 1, vector<P>());
    vector<int> Dist(N + 1, INF);
    vector<vector<int>> Pass(N + 1, vector<int>());
    for (int i = 0; i < M; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;

        Map[s].push_back({e, t});
    }
    cin >> S >> E;

    Dijkstra(S, Map, Dist, Pass);
    Pass[E].push_back(E);
    cout << Dist[E] << '\n';
    cout << Pass[E].size() << '\n';
    for (int i = 0; i < Pass[E].size(); i++)
        cout << Pass[E][i] << " ";
    return 0;
}
void Dijkstra(int start, vector<vector<P>> &Map, vector<int> &Dist, vector<vector<int>> &Pass)
{
    priority_queue<P, vector<P>, compare> pq;
    pq.push({start, 0});
    Dist[start] = 0;

    while (!pq.empty())
    {
        P cur = pq.top();
        pq.pop();

        for (int i = 0; i < Map[cur.first].size(); i++)
        {
            P next = Map[cur.first][i];
            int cost = cur.second + next.second;
            if (cost <= Dist[next.first])
            {
                if (cost == Dist[next.first])
                    Pass[next.first].erase(Pass[next.first].end() - 1);
                Dist[next.first] = cost;
                Pass[next.first].push_back(cur.first);
                pq.push({next.first, cost});
            }
        }
    }
}