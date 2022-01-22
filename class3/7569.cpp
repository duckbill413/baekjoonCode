#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

//상하좌우앞뒤
const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};
int N, M, H;

typedef struct _point
{
    int x, y, z; //x,y,z좌표
} Point;
bool inRange(Point p);
void BFS(int ***map, int ***visit, int ***time);
void setQue(queue<Point> *q, int ***map, int ***visit, int ***time);

int main()
{
    cin >> M >> N >> H;

    //토마토의 Map과 방문여부 및 일을 확인 하는 visit 생성
    int ***map = new int **[N];
    for (int i = 0; i < N; i++)
    {
        map[i] = new int *[M];
        for (int j = 0; j < M; j++)
            map[i][j] = new int[H];
    }
    int ***visit = new int **[N];
    for (int i = 0; i < N; i++)
    {
        visit[i] = new int *[M]();
        for (int j = 0; j < M; j++)
            visit[i][j] = new int[H]();
    }
    int ***time = new int **[N];
    for (int i = 0; i < N; i++)
    {
        time[i] = new int *[M]();
        for (int j = 0; j < M; j++)
            time[i][j] = new int[H]();
    }
    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> map[i][j][k];

    BFS(map, visit, time);
    int Time = 0;
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < H; k++)
            {
                if (map[i][j][k] != -1 && visit[i][j][k])
                {
                    if (Time < time[i][j][k])
                        Time = time[i][j][k];
                }
                if (map[i][j][k] != -1 && !visit[i][j][k])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
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
        for (int j = 0; j < M; j++)
        {
            delete[] map[i][j];
            delete[] visit[i][j];
            delete[] time[i][j];
        }
        delete[] map[i];
        delete[] visit[i];
        delete[] time[i];
    }
    delete[] time;
    delete[] map;
    delete[] visit;
}
void setQue(queue<Point> *q, int ***map, int ***visit, int ***time)
{
    Point tmp;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < H; k++)
            {
                if (map[i][j][k] == 1)
                {
                    visit[i][j][k] = 1;
                    time[i][j][k] = 0;
                    tmp.x = i;
                    tmp.y = j;
                    tmp.z = k;
                    q->push(tmp);
                }
            }
}
void BFS(int ***map, int ***visit, int ***time)
{
    queue<Point> q;
    setQue(&q, map, visit, time);
    Point now, next;

    while (!q.empty())
    {
        now = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            next.z = now.z + dz[i];

            if (inRange(next) && map[next.x][next.y][next.z] == 0 && !visit[next.x][next.y][next.z])
            {
                q.push(next);
                visit[next.x][next.y][next.z] = 1;
                time[next.x][next.y][next.z] = time[now.x][now.y][now.z] + 1;
            }
        }
    }
}
bool inRange(Point p)
{
    if ((p.x < 0 || p.y < 0 || p.z < 0) || (p.x >= N || p.y >= M || p.z >= H))
        return false;
    return true;
}