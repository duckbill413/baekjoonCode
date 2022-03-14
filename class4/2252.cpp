// 2252 줄 세우기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
void BFS(vector<vector<int>> &line, vector<int> &in_degree);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> line(N + 1, vector<int>());
    vector<int> in_degree(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        line[a].push_back(b);
        in_degree[b]++;
    }

    BFS(line, in_degree);
}
void BFS(vector<vector<int>> &line, vector<int> &in_degree)
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);

        for (int i = 0; i < line[cur].size(); i++)
        {
            int next = line[cur][i];
            in_degree[next]--;
            if (in_degree[next] == 0)
                q.push(next);
        }
    }
}