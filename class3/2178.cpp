//중요도!!!
// BFS 알고리즘 및 Pair
#include <iostream>
#include <queue>
#include <utility> //pair사용
using namespace std;
int N, M; // kk,
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// BFS(너비 우선 알고리즘)
void Route(int **board, int **visit);

int main()
{
    // Input
    cin >> N >> M;
    int **board = new int *[N];
    for (int i = 0; i < N; i++)
        board[i] = new int[M];
    //미로 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &board[i][j]);
    //방문 여부 및 시간
    int **visit = new int *[N + 1];
    for (int i = 0; i < N + 1; i++)
        visit[i] = new int[M + 1]();

    Route(board, visit); // BFS

    cout << visit[N - 1][M - 1]; // N, M위치의 시간 출력

    for (int i = 0; i < N; i++)
        delete[] board[i];
    delete[] board;
    for (int i = 0; i < N + 1; i++)
        delete[] visit[i];
    delete[] visit;
}
void Route(int **board, int **visit)
{
    queue<pair<int, int>> q; // x, y좌표 입력 큐 생성
    q.push(make_pair(0, 0)); //시작점 입력
    visit[0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ((nx >= 0 && ny >= 0) && (nx < N && ny < M) && board[nx][ny] && visit[nx][ny] == 0)
            {
                q.push(make_pair(nx, ny));
                visit[nx][ny] = visit[x][y] + 1;
            }
        }
    }
}