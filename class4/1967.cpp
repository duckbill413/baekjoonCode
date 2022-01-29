// 중요도!!!!
// 1967 트리의 지름
// DFS 알고리즘, 다익스트라 알고리즘
/* NOTE: 트리의 지름 공식
1) 임의의 한 노드로 부터 거리가 가장 긴 마지막 정점을 구한다
2) 마지막 정점으로 부터 거기가 가장 긴 정점을 구한다.
3) 1, 2에서 구한 두 개의 길이 중 긴 길이가 트리의 지름 */
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> P;

void DFS(P p, vector<vector<P>> &tree, vector<int> &visited, int len, P &range);
void VisitInit(vector<int> &visited);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<vector<P>> tree(N + 1, vector<P>());
    vector<int> visited(N + 1, -1);
    for (int i = 0; i < N - 1; i++)
    {
        int node, next, cost;
        cin >> node >> next >> cost;
        tree[node].push_back(make_pair(next, cost));
        tree[next].push_back(make_pair(node, cost));
    }

    P range;
    DFS(make_pair(1, 0), tree, visited, 0, range);
    VisitInit(visited);
    DFS(range, tree, visited, 0, range);
    cout << range.second;
}
void DFS(P p, vector<vector<P>> &tree, vector<int> &visited, int len, P &range)
{
    visited[p.first] = len;
    if (range.second < len)
    {
        range.first = p.first;
        range.second = len;
    }
    for (int i = 0; i < tree[p.first].size(); i++)
    {
        P next = tree[p.first][i];
        if (visited[next.first] == -1)
            DFS(next, tree, visited, len + next.second, range);
    }
}
void VisitInit(vector<int> &visited)
{
    for (int i = 0; i < visited.size(); i++)
        visited[i] = -1;
}