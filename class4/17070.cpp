// 17070 파이프 옮기기 1
#include <iostream>
#include <vector>
using namespace std;
const int dx[] = {0, 1, 1};
const int dy[] = {1, 0, 1};
int ans, N;

bool checkWall(int x, int y, vector<vector<int>> &Dist)
{
    if (x < 1 || y < 1 || x > N || y > N || Dist[x][y] == 1)
        return true;
    return false;
}
void DFS(int x, int y, int mode, vector<vector<int>> &Dist)
{
    if (x == N && y == N)
    {
        ans++;
        return;
    }
    // mode : (1) 가로 이동, (2) 세로 이동, (3) 대각선 이동
    for (int i = 0; i < 3; i++)
    {
        if ((mode == 0 && i == 1) || (mode == 1 && i == 0))
            continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (checkWall(nx, ny, Dist))
            continue;
        if (i == 2 && (Dist[x + 1][y] == 1 || Dist[x][y + 1] == 1))
            continue;
        DFS(nx, ny, i, Dist);
    }
}
int main()
{
    cin >> N;
    vector<vector<int>> Dist(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> Dist[i][j];

    ans = 0;
    DFS(1, 2, 0, Dist); //시작위치(1, 2)
    cout << ans;
}