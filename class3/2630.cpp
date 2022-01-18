//중요도!!
//분할정복, 재귀
#include <iostream>
using namespace std;

int white = 0, blue = 0;
void Block(int **map, int row, int col, int size);

int main()
{
    int N;
    cin >> N;
    int **map = new int *[N];
    for (int i = 0; i < N; i++)
        map[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    Block(map, 0, 0, N);

    cout << white << endl;
    cout << blue;

    for (int i = 0; i < N; i++)
        delete[] map[i];
    delete[] map;
    return 0;
}
void Block(int **map, int row, int col, int size)
{
    int pivot = map[row][col];
    int flag = 0;
    for (int i = row; i < row + size; i++)
    {
        for (int j = col; j < col + size; j++)
        {
            if (pivot != map[i][j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }

    if (!flag)
    {
        if (pivot)
            blue++;
        else
            white++;
    }
    else
    {
        int resize = size / 2;
        Block(map, row, col, resize);
        Block(map, row, col + resize, resize);
        Block(map, row + resize, col, resize);
        Block(map, row + resize, col + resize, resize);
    }
}