// ��Ʈ�ι̳�
// �߿䵵!!!
// DFS, ���Ʈ����
#include <iostream>
#include <vector>
#include <utility>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int ans = 0, N, M; //����(���� ū ��), ����, ����
// DFS �Ǹ�� ���� DFS ����Ͽ� Ž��
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
        //�湮 ������ ��� �� ����Ŭ�� ���ؼ��� ��ȿ�ϹǷ� ���� �ʱ�ȭ
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

            //��, �� ����϶�
            if (j + 2 < M)
            {
                int tmp = board[i][j] + board[i][j + 1] + board[i][j + 2];
                if (i + 1 < N)
                    ans = MAX(ans, tmp + board[i + 1][j + 1]);
                if (i > 0)
                    ans = MAX(ans, tmp + board[i - 1][j + 1]);
            }
            //��, �� ����϶�
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