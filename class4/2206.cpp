// 2206 벽 부수고 이동하기
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> P;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N, M;

void BFS(vector<vector<int>> &board, vector<vector<vector<int>>> &visited);

int main()
{
    scanf("%d %d", &N, &M);

    vector<vector<int>> board(N + 1, vector<int>(M + 1, 0));
    vector<vector<vector<int>>> visited(N + 1, vector<vector<int>>(M + 1, vector<int>(2, -1)));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            scanf("%1d", &board[i][j]);
    }

    BFS(board, visited);
    if (visited[N][M][1] != -1)
        cout << visited[N][M][1];
    else
        cout << visited[N][M][0];
}

void BFS(vector<vector<int>> &board, vector<vector<vector<int>>> &visited)
{
    queue<P> q;
    q.push({{1, 1}, 0});
    visited[1][1][0] = 1;
    visited[1][1][1] = 1;

    while (!q.empty())
    {
        P cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > M)
                continue;

            if (board[nx][ny] == 1 && cur.second == 0)
            {
                visited[nx][ny][1] = visited[cur.first.first][cur.first.second][0] + 1;
                q.push({{nx, ny}, 1});
            }
            else if (board[nx][ny] == 0 && visited[nx][ny][cur.second] == -1)
            {
                visited[nx][ny][cur.second] = visited[cur.first.first][cur.first.second][cur.second] + 1;
                q.push({{nx, ny}, cur.second});
            }
        }
    }
}