// 14502 연구소
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N, M;
int MAX;
queue<P> VirusInit(vector<vector<int>> &arr, vector<vector<int>> &visited);
void BFS(queue<P> q, vector<vector<int>> &arr, vector<vector<int>> &visited);
void WallDFS(P idx, int cnt, vector<vector<int>> &visited, vector<vector<int>> &arr);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0)); // DFS탐색을 통하여 순열 결정
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    WallDFS({0, 0}, 0, visited, arr);
    cout << MAX;
    return 0;
}
void WallDFS(P idx, int cnt, vector<vector<int>> &visited, vector<vector<int>> &arr)
{
    if (cnt == 3)
    {
        vector<vector<int>> table = arr; // table을 복사해주며 벽의 위치를 적용
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (visited[i][j] == 1)
                {
                    table[i][j] = 1;
                }
        vector<vector<int>> bfsVisit(N, vector<int>(M, 0));
        queue<P> q = VirusInit(table, bfsVisit); // visit을 초기화
        BFS(q, table, bfsVisit);
        int tmp = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (bfsVisit[i][j] == 0)
                    tmp++;
            }

        if (tmp > MAX)
            MAX = tmp;
        return;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == 1 || arr[i][j] == 2 || arr[i][j] == 1) //이미 방문한 경우, 바이러스 위치, 벽의 위치는 고려X
                continue;
            visited[i][j] = 1;
            WallDFS({i, j}, cnt + 1, visited, arr);
            visited[i][j] = 0;
        }
}
queue<P> VirusInit(vector<vector<int>> &arr, vector<vector<int>> &visited)
{
    queue<P> q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] != 0)
            {
                visited[i][j] = 1;
                if (arr[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }
    return q;
}
void BFS(queue<P> q, vector<vector<int>> &arr, vector<vector<int>> &visited)
{
    while (!q.empty())
    {
        P cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (arr[nx][ny] == 0 && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}