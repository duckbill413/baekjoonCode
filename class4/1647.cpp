// 1647 도시 분할 계획
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
typedef pair<int, pair<int, int>> T;

int findParent(int, vector<int> &);
void unionEdge(int, int, vector<int> &, int &);
int sameParent(int, int, vector<int> &);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<T> Edge;
    for (int i = 0; i < M; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        Edge.push_back({c, {s, e}}); //가중치를 기준으로 정렬하기 위하여 가중치를 1번 값으로 한다.
    }
    sort(Edge.begin(), Edge.end());
    vector<int> parent(N + 1, 0);
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    int total = 0, final = 0;
    for (int i = 0; i < M; i++)
    {
        if (!sameParent(Edge[i].second.first, Edge[i].second.second, parent))
        {
            unionEdge(Edge[i].second.first, Edge[i].second.second, parent, N);
            total += Edge[i].first;
            final = Edge[i].first;
        }
    }
    cout << total - final;
}
int findParent(int s, vector<int> &parent)
{
    if (parent[s] == s)
        return s;
    else
        return parent[s] = findParent(parent[s], parent);
}
int sameParent(int s, int e, vector<int> &parent)
{
    s = findParent(s, parent);
    e = findParent(e, parent);

    if (s == e)
        return true;
    else
        return false;
}
void unionEdge(int s, int e, vector<int> &parent, int &N)
{
    s = findParent(s, parent);
    e = findParent(e, parent);

    if (s != e)
    {
        parent[e] = s;
        N--;
    }
}