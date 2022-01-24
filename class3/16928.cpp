// 16928 뱀과 사다리 게임
// importance!!!
// BFS algorithm
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> &board, vector<int> &visited);

int main()
{
    int N, M; //사다리, 뱀의 수
    cin >> N >> M;
    vector<int> board(101, 0);
    vector<int> visited(101, -1);
    for (int i = 0; i < N + M; i++)
    {
        int point, target;
        cin >> point >> target;
        board[point] = target;
    }
    BFS(board, visited);

    cout << visited[100];
    return 0;
}
void BFS(vector<int> &board, vector<int> &visited)
{
    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int next = cur + i;
            if (next < 1 && next > 100)
                continue;
            if (board[next] != 0 && visited[next] == -1)
            {
                visited[next] = visited[cur];
                next = board[next];
            }
            if (visited[next] == -1)
            {
                q.push(next);
                visited[next] = visited[cur] + 1;
            }
        }
    }
}