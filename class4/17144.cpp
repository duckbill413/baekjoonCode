// 17144 미세먼지 안녕!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void afterSecond(vector<vector<int>> &room);
queue<P> setQueue(vector<vector<int>> &room);
int R, C, T;
int air;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> T;
    vector<vector<int>> room(R + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == -1)
                air = i;
        }
    while (T--)
        afterSecond(room);
    int dust = 0;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (room[i][j] > 0)
                dust += room[i][j];
    cout << dust;
}
queue<P> setQueue(vector<vector<int>> &room)
{
    queue<P> q;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            if (room[i][j] > 0)
                q.push({i, j});
        }
    return q;
}
void afterSecond(vector<vector<int>> &room)
{
    //미세먼지의 위치
    queue<P> q = setQueue(room);
    vector<vector<int>> roomUpdate = room;
    //미세먼지의 확산
    while (!q.empty())
    {
        P cur = q.front();
        q.pop();

        int tmp = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 1 || ny < 1 || nx > R || ny > C || room[nx][ny] == -1)
                continue;

            roomUpdate[nx][ny] += room[cur.first][cur.second] / 5;
            tmp += room[cur.first][cur.second] / 5;
        }
        roomUpdate[cur.first][cur.second] -= tmp;
    }
    // 공기청정기 작동
    // 위쪽
    for (int i = air - 1; i > 1; i--)
        roomUpdate[i][1] = roomUpdate[i - 1][1];
    roomUpdate[air - 1][1] = -1;
    for (int i = 1; i < C; i++)
        roomUpdate[1][i] = roomUpdate[1][i + 1];
    for (int i = 1; i < air - 1; i++)
        roomUpdate[i][C] = roomUpdate[i + 1][C];
    for (int i = C; i > 1; i--)
        roomUpdate[air - 1][i] = roomUpdate[air - 1][i - 1];
    roomUpdate[air - 1][2] = 0;
    //아래쪽
    for (int i = air; i < R; i++)
        roomUpdate[i][1] = roomUpdate[i + 1][1];
    roomUpdate[air][1] = -1;
    for (int i = 1; i < C; i++)
        roomUpdate[R][i] = roomUpdate[R][i + 1];
    for (int i = R; i > air; i--)
        roomUpdate[i][C] = roomUpdate[i - 1][C];
    for (int i = C; i > 1; i--)
        roomUpdate[air][i] = roomUpdate[air][i - 1];
    roomUpdate[air][2] = 0;
    room = roomUpdate;
}