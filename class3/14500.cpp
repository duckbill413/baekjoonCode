<<<<<<< HEAD
// ��Ʈ�ι̳�
// �߿䵵!!!
// DFS, ���Ʈ���� �˰�����
=======
// 테트로미노
// 중요도!!!
// DFS, 브루트포스 알고리즘
>>>>>>> 1157688bce8f9ed16aed5db091e2527652efc2cc
#include <iostream>
#include <vector>
#include <utility>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int ans = 0, N, M; //정답(가장 큰 값), 세로, 가로
// DFS ㅗ모양 제외 DFS 사용하여 탐색
void DFS(pair<int, int> p, vector<vector<int>> &board, vector<vector<int>> &visit, int sum, int size)
{
    if (size == 4)
    {
        ans = MAX(ans, sum);
        return;
    }

    if (p.first < 0 || p.second < 0 || p.first >= N || p.second >= M)
        return;

    if (!visit[p.first][p.second])
    {
        //방문 여부의 경우 한 사이클에 대해서만 유효하므로 이후 초기화
        visit[p.first][p.second] = 1;
        for (int i = 0; i < 4; i++)
            DFS(make_pair(p.first + dx[i], p.second + dy[i]), board, visit, sum + board[p.first][p.second], size + 1);
        visit[p.first][p.second] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            DFS(make_pair(i, j), board, visited, 0, 0);

            //ㅗ, ㅜ 모양일때
            if (j + 2 < M)
            {
                int tmp = board[i][j] + board[i][j + 1] + board[i][j + 2];
                if (i + 1 < N)
                    ans = MAX(ans, tmp + board[i + 1][j + 1]);
                if (i > 0)
                    ans = MAX(ans, tmp + board[i - 1][j + 1]);
            }
            //ㅏ, ㅓ 모양일때
            if (i + 2 < N)
            {
                int tmp = board[i][j] + board[i + 1][j] + board[i + 2][j];
                if (j + 1 < M)
                    ans = MAX(ans, tmp + board[i + 1][j + 1]);
                if (j > 0)
                    ans = MAX(ans, tmp + board[i + 1][j - 1]);
            }
        }

    cout << ans;
    return 0;
}
