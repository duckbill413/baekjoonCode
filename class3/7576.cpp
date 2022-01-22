//중요도!!!!
// BFS 동시 진행
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

//상하좌우
const int dx[] = {-1, 1, 0, 0}; //세로
const int dy[] = {0, 0, -1, 1}; //가로
int N, M;                       // N은 세로, M은 가로

//최소 일수를 구하므로 BFS 알고리즘 이용
void BFS(int **map, int **visit, int **time);
void setQue(queue<pair<int, int>> *q, int **map, int **visit, int **time);
int main()
{
    cin >> M >> N;

    //토마토의 Map과 방문여부및 일을 확인하는 visit 생성
    int **map = new int *[N];
    for (int i = 0; i < N; i++)
        map[i] = new int[M];

    int **visit = new int *[N];
    for (int i = 0; i < N; i++)
        visit[i] = new int[M]();

    int **time = new int *[N];
    for (int i = 0; i < N; i++)
        time[i] = new int[M]();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    BFS(map, visit, time);
    int Time = 0;
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] != -1 && visit[i][j])
            {
                if (Time < time[i][j])
                    Time = time[i][j];
            }
            if (map[i][j] != -1 && !visit[i][j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
        cout << -1;
    else
        cout << Time;

    for (int i = 0; i < N; i++)
    {
        delete[] map[i];
        delete[] visit[i];
        delete[] time[i];
    }
    delete[] time;
    delete[] map;
    delete[] visit;
}
void setQue(queue<pair<int, int>> *q, int **map, int **visit, int **time)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
            {
                visit[i][j] = 1;
                time[i][j] = 0;
                q->push(make_pair(i, j));
            }
        }
}
void BFS(int **map, int **visit, int **time)
{
    queue<pair<int, int>> q;
    setQue(&q, map, visit, time); //토마토가 있을 경우 우선적으로 탐색해 주기 위함
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ((nx >= 0 && ny >= 0) && (nx < N && ny < M) && map[nx][ny] == 0 && visit[nx][ny] == 0)
            {
                q.push(make_pair(nx, ny));
                visit[nx][ny] = 1;
                time[nx][ny] = time[x][y] + 1;
            }
        }
    }
}