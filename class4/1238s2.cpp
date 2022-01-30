// 중요도!!!!
// 다익스트라 알고리즘(길찾기) <= 시간복잡도 Big(N^2)
/*
1. 시작 노드와 연결된 모든 정점들의 거리를 비교하여 업데이트 시켜주고, 시작 노드를 방문한 노드로 체크
2. 방문한 정점들과 연결되어 있는 정점들 중, 비용이 가장 적게 드는 정점을 선택하고, 해당 정점을 방문한 정점으로 선택
3. 2번 과정에 의해서 갱실 될 수 있는 정점들의 거리를 갱신
4. 2~3 과정을 반복 */
// FIXME: BIG(N^2) 의 시간복잡도로 인하여 시간 초과 발생
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
typedef pair<int, int> P;

void ValueInit(vector<int> &visited, vector<int> &Dist);
void Dijkstra(int start, vector<vector<P>> &road, vector<int> &visited, vector<int> &Dist);
void UpdataDist(int cur, vector<vector<P>> &road, vector<int> &visited, vector<int> &Dist);
int FindNode(vector<int> &visited, vector<int> &Dist);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<P>> road(N + 1, vector<P>()); // 정점 -> 목적지 & 비용
    vector<int> visited(N + 1, 0);              // 방문 확인
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
        Dijkstra(i, road, visited, Dist);
        cost[i] += Dist[X];
        ValueInit(visited, Dist);
        Dijkstra(X, road, visited, Dist);
        cost[i] += Dist[i];
        ValueInit(visited, Dist);
    }
    int longest = 0;
    for (int i = 1; i <= N; i++)
        if (longest < cost[i])
            longest = cost[i];

    cout << longest;
    return 0;
}
int FindNode(vector<int> &visited, vector<int> &Dist)
{
    int minDist = INF, minNode = -1;
    for (int i = 1; i <= visited.size() - 1; i++)
    {
        if (Dist[i] < minDist && !visited[i])
        {
            minNode = i;
            minDist = Dist[i];
        }
    }
    return minNode;
}
void Dijkstra(int start, vector<vector<P>> &road, vector<int> &visited, vector<int> &Dist)
{
    Dist[start] = 0;
    visited[start] = 1;
    for (int i = 0; i < road[start].size(); i++)
        Dist[road[start][i].first] = road[start][i].second;

    for (int i = 1; i < road.size() - 1; i++)
    {
        int next = FindNode(visited, Dist);
        visited[next] = 1;

        for (int j = 0; j < road[next].size(); j++)
        {
            int cost = Dist[next] + road[next][j].second;
            if (cost < Dist[road[next][j].first])
                Dist[road[next][j].first] = cost;
        }
    }
}
void ValueInit(vector<int> &visited, vector<int> &Dist)
{
    int size = visited.size();
    for (int i = 0; i < visited.size(); i++)
    {
        visited[i] = 0;
        Dist[i] = INF;
    }
}