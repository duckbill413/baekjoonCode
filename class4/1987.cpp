// 1987 알파벳
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> P;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int R, C;
int ans;
vector<int> alpha(26, 0);
void DFS(P p, int cost, vector<vector<char>> &table)
{
    if (ans < cost)
        ans = cost;

    for (int i = 0; i < 4; i++)
    {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];

        if (nx < 1 || ny < 1 || nx > R || ny > C)
            continue;

        if (!alpha[table[nx][ny] - 'A'])
        {
            alpha[table[nx][ny] - 'A'] = 1;
            DFS({nx, ny}, cost + 1, table);
            alpha[table[nx][ny] - 'A'] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    vector<vector<char>> table(R + 1, vector<char>(C + 1, 0));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
            cin >> table[i][j];
    }

    alpha[table[1][1] - 'A'] = 1;
    DFS({1, 1}, 1, table);
    cout << ans;
}