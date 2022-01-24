// 16236 아기 상어
// importance!!!!
// BFS algorithm per node
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef struct _shark
{
    int x, y;
    int eat;
    int size;
} Shark;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

Shark s;
int time;
int mx, my, mdistance;
int N;

void initDistance(vector<vector<int>> &distance)
{
    for (auto &i : distance)
        for (auto &j : i)
            j = -1;

    mx = my = distance.size();
    mdistance = mx * my + 1;
}
void BFS(pair<int, int> p, vector<vector<int>> &board, vector<vector<int>> &distance)
{
    queue<pair<int, int>> q;
    distance[p.first][p.second] = 0;
    q.push(make_pair(p.first, p.second));

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) //범위를 벗어남
                continue;
            if (distance[nx][ny] != -1 || board[nx][ny] > s.size) //물고기 크기가 더 큰 경우와 이미 방문한 경우
                continue;

            distance[nx][ny] = distance[cur.first][cur.second] + 1;

            if (board[nx][ny] != 0 && board[nx][ny] < s.size) //먹을 수 있는 물고기인 경우
            {
                if (mdistance > distance[nx][ny])
                {
                    mx = nx;
                    my = ny;
                    mdistance = distance[nx][ny];
                }
                else if (mdistance == distance[nx][ny])
                {
                    if (mx == nx)
                    {
                        if (my > ny)
                        {
                            mx = nx;
                            my = ny;
                        }
                    }
                    else if (mx > nx)
                    {
                        mx = nx;
                        my = ny;
                    }
                    // mx==mx or mx > nx 모두 아닌 경우는 어차피 경우가 1개이다
                }
            }
            q.push(make_pair(nx, ny));
        }
    }
}
int main()
{
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<int>> distance(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                s.x = i;
                s.y = j;
                s.eat = 0;
                s.size = 2;
                board[i][j] = 0; //지나갈 수 있는 경로
            }
        }

    while (true)
    {
        initDistance(distance); //좌표에 대한 거리는 매번 초기화 필요
        BFS(make_pair(s.x, s.y), board, distance);

        if (mx != N && my != N)
        {
            time += distance[mx][my];
            // cout << "최소거리 좌표: " << mx << " " << my << " "
            //      << "size: " << s.size << " " << mdistance << " 누적 시간: " << time << '\n';
            s.eat++;
            if (s.eat == s.size)
            {
                s.eat = 0;
                s.size += 1;
            }

            board[mx][my] = 0;
            s.x = mx;
            s.y = my;
        }
        else
            break;
    }

    cout << time;
    return 0;
}
