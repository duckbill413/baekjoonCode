#include <iostream>
#include <vector>
#define ROW 3072
#define COL 6144
using namespace std;

vector<vector<char>> star(ROW, vector<char>(COL, ' '));

void MakeStar(int len, int x, int y);
void DrawStar(int x, int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    MakeStar(N, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
            cout << star[i][j];
        cout << '\n';
    }
}
void MakeStar(int len, int x, int y)
{
    if (len == 3)
    {
        DrawStar(x, y);
        return;
    }

    MakeStar(len / 2, x, y);
    MakeStar(len / 2, x + len / 2, y - len / 2);
    MakeStar(len / 2, x + len / 2, y + len / 2);
}
void DrawStar(int x, int y)
{
    star[x][y] = '*';
    star[x + 1][y - 1] = star[x + 1][y + 1] = '*';
    for (int i = 0; i < 5; i++)
        star[x + 2][y - 2 + i] = '*';
}