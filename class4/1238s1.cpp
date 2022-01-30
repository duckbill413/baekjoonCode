// 1238 파티
// 중요도!!!!
// 다익스트라 알고리즘(길찾기) <= 시간복잡도 Big(ElogN) : E는 간선의 개수
/*
1. 시작 노드와 연결된 모든 정점들의 거리를 비교하여 업데이트 시켜주고, 시작 노드를 방문한 노드로 체크
2. 방문한 정점들과 연결되어 있는 정점들 중, 비용이 가장 적게 드는 정점을 선택하고, 해당 정점을 방문한 정점으로 선택
3. 2번 과정에 의해서 갱실 될 수 있는 정점들의 거리를 갱신
4. 2~3 과정을 반복 */
#include <iostream>
#include <vector>
#include <queue>
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
void ValueInit(vector<int> &Dist);
void Dijkstra(int start, vector<vector<P>> &road, vector<int> &Dist);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<P>> road(N + 1, vector<P>()); // 정점 -> 목적지 & 비용
    vector<int> Dist(N + 1, INF);               //다익스트라 알고리즘 실행 중 비용 저장
    vector<int> cost(N + 1, 0);                 //각 노드 별 비용 저장
    for (int i = 0; i < M; i++)
    {
        int A, B, T;
        cin >> A >> B >> T;
        road[A].push_back(make_pair(B, T));
    }

    for (int i = 1; i <= N; i++)
    {
        if (i == X) // i==X인 경우의 거리는 0 고정
            continue;
        Dijkstra(i, road, Dist);
        cost[i] += Dist[X];
        ValueInit(Dist);
        Dijkstra(X, road, Dist);
        cost[i] += Dist[i];
        ValueInit(Dist);
    }
    int longest = 0;
    for (int i = 1; i <= N; i++)
        if (longest < cost[i])
            longest = cost[i];
    cout << longest;
    return 0;
}
void Dijkstra(int start, vector<vector<P>> &road, vector<int> &Dist)
{
    priority_queue<P, vector<P>, compare> pq;
    pq.push(make_pair(start, 0));
    Dist[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        for (int i = 0; i < road[cur].size(); i++)
        {
            int next = road[cur][i].first;
            int cost = dist + road[cur][i].second;
            if (cost < Dist[next])
            {
                Dist[next] = cost;
                pq.push(make_pair(next, cost));
            }
        }
    }
}
void ValueInit(vector<int> &Dist)
{
    for (int i = 0; i < Dist.size(); i++)
        Dist[i] = INF;
}