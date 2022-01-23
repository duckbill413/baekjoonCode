//중요도 !!!!
// 경로 찾기 알고리즘(BFS)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int r, vector<vector<int>> &board, vector<vector<int>> &visited);
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>());
    vector<vector<int>> visited(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp)
            {
                board[i].push_back(j);
            }
        }
    for (int i = 0; i < board.size(); i++)
        if (board[i].size() > 0)
            BFS(i, board, visited);

    for (auto i : visited)
    {
        for (auto j : i)
            cout << j << " ";
        cout << '\n';
    }
}

void BFS(int r, vector<vector<int>> &board, vector<vector<int>> &visited)
{
    queue<int> q;
    for (int i = 0; i < board[r].size(); i++)
    {
        q.push(board[r][i]);
        visited[r][board[r][i]] = 1;
    }

    while (!q.empty())
    {
        int next = q.front();
        q.pop();
        for (int i = 0; i < board[next].size(); i++)
        {
            int nextnext = board[next][i];
            if (!visited[r][nextnext])
            {
                q.push(nextnext);
                visited[r][nextnext] = 1;
            }
        }
    }
}