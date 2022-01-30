// 1238 ��Ƽ
// �߿䵵!!!!
// ���ͽ�Ʈ�� �˰���(��ã��) <= �ð����⵵ Big(ElogN) : E�� ������ ����
/*
1. ���� ���� ����� ��� �������� �Ÿ��� ���Ͽ� ������Ʈ �����ְ�, ���� ��带 �湮�� ���� üũ
2. �湮�� ������� ����Ǿ� �ִ� ������ ��, ����� ���� ���� ��� ������ �����ϰ�, �ش� ������ �湮�� �������� ����
3. 2�� ������ ���ؼ� ���� �� �� �ִ� �������� �Ÿ��� ����
4. 2~3 ������ �ݺ� */
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
    vector<vector<P>> road(N + 1, vector<P>()); // ���� -> ������ & ���
    vector<int> Dist(N + 1, INF);               //���ͽ�Ʈ�� �˰��� ���� �� ��� ����
    vector<int> cost(N + 1, 0);                 //�� ��� �� ��� ����
    for (int i = 0; i < M; i++)
    {
        int A, B, T;
        cin >> A >> B >> T;
        road[A].push_back(make_pair(B, T));
    }

    for (int i = 1; i <= N; i++)
    {
        if (i == X) // i==X�� ����� �Ÿ��� 0 ����
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