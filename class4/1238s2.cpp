// �߿䵵!!!!
// ���ͽ�Ʈ�� �˰���(��ã��) <= �ð����⵵ Big(N^2)
/*
1. ���� ���� ����� ��� �������� �Ÿ��� ���Ͽ� ������Ʈ �����ְ�, ���� ��带 �湮�� ���� üũ
2. �湮�� ������� ����Ǿ� �ִ� ������ ��, ����� ���� ���� ��� ������ �����ϰ�, �ش� ������ �湮�� �������� ����
3. 2�� ������ ���ؼ� ���� �� �� �ִ� �������� �Ÿ��� ����
4. 2~3 ������ �ݺ� */
// FIXME: BIG(N^2) �� �ð����⵵�� ���Ͽ� �ð� �ʰ� �߻�
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
    vector<vector<P>> road(N + 1, vector<P>()); // ���� -> ������ & ���
    vector<int> visited(N + 1, 0);              // �湮 Ȯ��
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