// dfs 알고리즘
#include <iostream>
using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
class WormBoard
{
private:
    bool board[51][51] = {0};
    bool visit[51][51] = {0};
    int row, col;
    int count;

public:
    WormBoard(int M, int N)
    {
        this->row = N;
        this->col = M;
        this->count = 0;
        int K;
        cin >> K;
        int x, y;
        while (K--)
        {
            cin >> y >> x;
            board[x][y] = true;
        }
    }
    void dfs(int x, int y)
    {
        visit[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (!inRange(rx, ry))
                continue;

            if (!board[rx][ry] || visit[rx][ry])
                continue;

            dfs(rx, ry);
        }
    }
    void showBoard()
    {
        cout << "board" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool inRange(int x, int y)
    {
        if (x < 0 || x >= row)
            return false;
        if (y < 0 || y >= col)
            return false;
        return true;
    }
    int wormCnt()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] && !visit[i][j])
                {
                    this->count++;
                    dfs(i, j);
                }
            }
        }
        return this->count;
    }
};

int main()
{
    int T; //테스트 케이스의 개수
    cin >> T;
    int M, N;
    while (T--)
    {
        cin >> M >> N;
        WormBoard b(M, N);
        // b.showBoard();
        cout << b.wormCnt() << endl;
    }

    return 0;
}