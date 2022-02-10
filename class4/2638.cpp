// 2638 치즈
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N, M;
void InOut(vector<vector<int>> &board, vector<vector<int>> &air, vector<vector<int>> &visited);
void Init(vector<vector<int>> &air, vector<vector<int>> &visited);
int Melt(vector<vector<int>> &board, vector<vector<int>> &air);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<vector<int>> board(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> air(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> visited(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];

    int day = 0;
    while (true)
    {
        Init(air, visited);
        InOut(board, air, visited); //바깥과 안 구별
        int flag = Melt(board, air);
        if (flag == 0)
            break;
        else
            day++;
    }

    cout << day;
}

void InOut(vector<vector<int>> &board, vector<vector<int>> &air, vector<vector<int>> &visited)
{
    queue<P> q;
    q.push({1, 1});

    while (!q.empty())
    {
        P cur = q.front();
        q.pop();
        if (visited[cur.first][cur.second])
            continue;
        visited[cur.first][cur.second] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > M)
                continue;

            if (board[nx][ny] == 1)
                air[nx][ny]++;
            else if (!visited[nx][ny])
                q.push({nx, ny});
        }
    }
}
void Init(vector<vector<int>> &air, vector<vector<int>> &visited)
{
    for (auto &i : visited)
        for (auto &j : i)
            j = 0;
    for (auto &i : air)
        for (auto &j : i)
            j = 0;
}
int Melt(vector<vector<int>> &board, vector<vector<int>> &air)
{
    int flag = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (air[i][j] >= 2)
            {
                board[i][j] = 0;
                flag = 1;
            }
        }
    return flag;
}