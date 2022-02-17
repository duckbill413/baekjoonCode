// 11660 구간 합 구하기 5
#include <iostream>
#include <vector>
using namespace std;

int sumBlock(vector<vector<int>> &matrix, pair<int, int> a, pair<int, int> b)
{
    return matrix[b.first][b.second] - matrix[a.first - 1][b.second] - matrix[b.first][a.second - 1] + matrix[a.first - 1][a.second - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            int tmp;
            cin >> tmp;
            if (i == 1 && j == 1)
                matrix[i][j] = tmp;
            else if (i == 1 && j != 1)
                matrix[i][j] = tmp + matrix[i][j - 1];
            else if (i != 1 && j == 1)
                matrix[i][j] = tmp + matrix[i - 1][j];
            else
                matrix[i][j] = tmp + matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
        }

    while (M--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << sumBlock(matrix, {x1, y1}, {x2, y2}) << '\n';
    }
}