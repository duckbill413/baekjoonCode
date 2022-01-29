// �߿䵵!!!!
// 1967 Ʈ���� ����
// DFS �˰���, ���ͽ�Ʈ�� �˰���
/* NOTE: Ʈ���� ���� ����
1) ������ �� ���� ���� �Ÿ��� ���� �� ������ ������ ���Ѵ�
2) ������ �������� ���� �űⰡ ���� �� ������ ���Ѵ�.
3) 1, 2���� ���� �� ���� ���� �� �� ���̰� Ʈ���� ���� */
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