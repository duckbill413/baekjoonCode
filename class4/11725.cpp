// 11725 트리의 부모 찾기
include <iostream>
#include <vector>
using namespace std;

void FindParent(int start, vector<vector<int>> &table, vector<int> &visited, vector<int> &parent);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> table(N + 1, vector<int>());
    vector<int> visited(N + 1, 0);
    vector<int> parent(N + 1, 0);

    for (int i = 0; i < N - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        table[s].push_back(e);
        table[e].push_back(s);
    }

    FindParent(1, table, visited, parent);

    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';
    return 0;
}
void FindParent(int start, vector<vector<int>> &table, vector<int> &visited, vector<int> &parent)
{
    visited[start] = 1;

    for (int i = 0; i < table[start].size(); i++)
    {
        int next = table[start][i];
        if (!visited[next])
        {
            parent[next] = start;
            FindParent(next, table, visited, parent);
        }
    }
}