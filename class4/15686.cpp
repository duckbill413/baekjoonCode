// 15686 치킨 배달
// DFS, BFS알고리즘을 이용한 풀이
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int N, M, len;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
void closeStore(int idx, int cnt, int target, vector<P> &store, vector<int> &visitStore,
                vector<vector<int>> &table, vector<vector<int>> &visited);
void BFS(queue<P> q, vector<vector<int>> &visited);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<vector<int>> table(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> visited(N + 1, vector<int>(N + 1, -1));
    vector<P> store;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> table[i][j];
            if (table[i][j] == 2)
                store.push_back({i, j});
        }
    vector<int> visitStore(store.size(), 0);

    len = 9999999;
    closeStore(0, 0, M, store, visitStore, table, visited);
    cout << len;
    return 0;
}
void closeStore(int idx, int cnt, int target, vector<P> &store, vector<int> &visitStore,
                vector<vector<int>> &table, vector<vector<int>> &visited)
{
    if (cnt == target)
    {
        queue<P> q;
        vector<vector<int>> TmpVisited = visited;
        for (int i = 0; i < visitStore.size(); i++)
        {
            if (visitStore[i] == 1)
            {
                q.push(store[i]);
                TmpVisited[store[i].first][store[i].second] = 0;
            }
            else
                TmpVisited[store[i].first][store[i].second] = -1;
        }
        BFS(q, TmpVisited);
        int tmpcnt = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (table[i][j] == 1)
                    tmpcnt += TmpVisited[i][j];
        if (len > tmpcnt)
            len = tmpcnt;
        return;
    }

    for (int i = idx; i < store.size(); i++)
    {
        if (visitStore[i] == 1)
            continue;
        visitStore[i] = 1;
        closeStore(i + 1, cnt + 1, target, store, visitStore, table, visited);
        visitStore[i] = 0;
    }
}
void BFS(queue<P> q, vector<vector<int>> &visited)
{
    while (!q.empty())
    {
        P cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > N)
                continue;

            if (visited[nx][ny] == -1)
            {
                q.push({nx, ny});
                visited[nx][ny] = visited[cur.first][cur.second] + 1;
            }
        }
    }
}