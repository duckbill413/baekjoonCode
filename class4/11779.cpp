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
void Dijkstra(int start, vector<vector<P>> &Map, vector<int> &Dist, vector<int> &Pass);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, S, E;
    cin >> N >> M;
    vector<vector<P>> Map(N + 1, vector<P>());
    vector<int> Dist(N + 1, INF);
    vector<int> Pass(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;

        Map[s].push_back({e, t});
    }
    cin >> S >> E;

    Dijkstra(S, Map, Dist, Pass);
    cout << Dist[E] << '\n';

    vector<int> ans;
    int tmp = E;
    while (tmp)
    {
        ans.push_back(tmp);
        tmp = Pass[tmp];
    }
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}
void Dijkstra(int start, vector<vector<P>> &Map, vector<int> &Dist, vector<int> &Pass)
{
    priority_queue<P, vector<P>, compare> pq;
    pq.push({start, 0});
    Dist[start] = 0;

    while (!pq.empty())
    {
        P cur = pq.top();
        pq.pop();

        // pq에 같은 번호의 노드가 여러개 들어갈 수도 있는데, 과거 pq에 넣어준 최단거리가 최근 갱신한 최단거리보다 클 경우 다익스트라를 할 필요가 없음
        if (cur.second > Dist[cur.first])
            continue;

        for (int i = 0; i < Map[cur.first].size(); i++)
        {
            P next = Map[cur.first][i];
            int cost = cur.second + next.second;
            if (cost < Dist[next.first])
            {
                Pass[next.first] = cur.first;
                Dist[next.first] = cost;
                pq.push({next.first, cost});
            }
        }
    }
}