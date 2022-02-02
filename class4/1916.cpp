// 1916 �ּҺ�� ���ϱ�
// �پǽ�Ʈ��
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
struct compare
{
    bool operator()(P a, P b)
    {
        return a.second > b.second;
    }
};

void Dijkstra(int start, vector<vector<P>> &Map, vector<int> &Dist);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, A, B;
    cin >> N >> M;
    vector<vector<P>> Map(N + 1, vector<P>());
    vector<int> Dist(N + 1, INF);

    for (int i = 0; i < M; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        Map[s].push_back({e, t});
    }
    cin >> A >> B;

    Dijkstra(A, Map, Dist);
    cout << Dist[B];
    return 0;
}
void Dijkstra(int start, vector<vector<P>> &Map, vector<int> &Dist)
{
    priority_queue<P, vector<P>, compare> pq;
    pq.push({start, 0});
    Dist[start] = 0;

    while (!pq.empty())
    {
        P cur = pq.top();
        pq.pop();

        // pq�� ���� ��ȣ�� ��尡 ������ �� ���� �ִµ�, ���� pq�� �־��� �ִܰŸ��� �ֱ� ������ �ִܰŸ����� Ŭ ��� ���ͽ�Ʈ�� �� �ʿ䰡 ����
        if (cur.second > Dist[cur.first])
            continue;

        for (int i = 0; i < Map[cur.first].size(); i++)
        {
            P next = Map[cur.first][i];
            int cost = cur.second + next.second;
            if (cost < Dist[next.first])
            {
                Dist[next.first] = cost;
                pq.push({next.first, cost});
            }
        }
    }
}