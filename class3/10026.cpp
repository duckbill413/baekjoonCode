//중요도!!!
// DFS알고리즘, 이중벡터의 사용
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N;
bool inRange(pair<int, int> p);
void NormalDFS(pair<int, int> p, vector<vector<char>> &board, vector<vector<bool>> &visit);
void BlindDFS(pair<int, int> p, vector<vector<char>> &board, vector<vector<bool>> &visit);
int main()
{
    cin >> N;

    vector<vector<char>> board(N, vector<char>(N, 0));
    vector<vector<bool>> visit1(N, vector<bool>(N, 0));
    vector<vector<bool>> visit2(N, vector<bool>(N, 0));

    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        for (int j = 0; j < N; j++)
            board[i][j] = tmp[j];
    }
    int normalCnt = 0, blindCnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (!visit1[i][j])
            {
                normalCnt++;
                NormalDFS(make_pair(i, j), board, visit1);
            }
            if (!visit2[i][j])
            {
                blindCnt++;
                BlindDFS(make_pair(i, j), board, visit2);
            }
        }

    cout << normalCnt << " " << blindCnt;
    return 0;
}
bool inRange(pair<int, int> p)
{
    if (p.first < 0 || p.second < 0 || p.first >= N || p.second >= N)
        return false;
    return true;
}
void NormalDFS(pair<int, int> p, vector<vector<char>> &board, vector<vector<bool>> &visit)
{
    visit[p.first][p.second] = true;
    char pivot = board[p.first][p.second];

    for (int i = 0; i < 4; i++)
    {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];

        if (!inRange(make_pair(nx, ny)))
            continue;

        if (board[nx][ny] == pivot && !visit[nx][ny])
            NormalDFS(make_pair(nx, ny), board, visit);
    }
}
void BlindDFS(pair<int, int> p, vector<vector<char>> &board, vector<vector<bool>> &visit)
{
    visit[p.first][p.second] = true;
    char pivot = board[p.first][p.second];

    for (int i = 0; i < 4; i++)
    {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];

        if (!inRange(make_pair(nx, ny)))
            continue;

        if ((pivot == 'R' || pivot == 'G') && (board[nx][ny] == 'R' || board[nx][ny] == 'G') && !visit[nx][ny])
            BlindDFS(make_pair(nx, ny), board, visit);
        else if (board[nx][ny] == pivot && !visit[nx][ny])
            BlindDFS(make_pair(nx, ny), board, visit);
    }
}