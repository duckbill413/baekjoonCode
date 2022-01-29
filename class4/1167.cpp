// 1167 트리의 지름
// BFS 알고리즘 이용
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int FarDistance(vector<vector<pair<int, int>>> &tree, vector<int> &visited);
void VisitInit(vector<int> &visited);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<vector<pair<int, int>>> tree(N + 1, vector<pair<int, int>>());
    vector<int> visited(N + 1, -1);
    for (int i = 0; i < N; i++)
    {
        int node;
        cin >> node;
        while (1)
        {
            int tmp;
            cin >> tmp;
            if (tmp == -1)
                break;
            int tmp2;
            cin >> tmp2;
            tree[node].push_back(make_pair(tmp, tmp2));
        }
    }
    int result = FarDistance(tree, visited);
    cout << result;
}
int FarDistance(vector<vector<pair<int, int>>> &tree, vector<int> &visited)
{
    int longest = 0;
    int longest_node = 1;
    queue<pair<int, int>> q;
    visited[longest_node] = 0;
    q.push(make_pair(1, 0));

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < tree[cur.first].size(); i++)
        {
            pair<int, int> next = tree[cur.first][i];
            if (visited[next.first] == -1)
            {
                q.push(next);
                visited[next.first] = visited[cur.first] + next.second;
                if (longest < visited[next.first])
                {
                    longest = visited[next.first];
                    longest_node = next.first;
                }
            }
        }
    }
    VisitInit(visited);
    visited[longest_node] = 0;
    q.push(make_pair(longest_node, 0));
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < tree[cur.first].size(); i++)
        {
            pair<int, int> next = tree[cur.first][i];
            if (visited[next.first] == -1)
            {
                q.push(next);
                visited[next.first] = visited[cur.first] + next.second;
                if (longest < visited[next.first])
                {
                    longest = visited[next.first];
                    longest_node = next.first;
                }
            }
        }
    }

    return longest;
}
void VisitInit(vector<int> &visited)
{
    for (int i = 0; i < visited.size(); i++)
        visited[i] = -1;
}