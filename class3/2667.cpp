#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int N;
int cnt = 0;

void dfs(pair<int, int> p, int **map, bool **visit, vector<int> &size);

int main()
{
    cin >> N;

    int **map = new int *[N];
    for (int i = 0; i < N; i++)
        map[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d", &map[i][j]);

    bool **visit = new bool *[N];
    for (int i = 0; i < N; i++)
        visit[i] = new bool[N]();

    vector<int> size;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[i][j] != 0 && !visit[i][j])
            {
                size.push_back(0);
                dfs(make_pair(i, j), map, visit, size);
                cnt++;
            }

    cout << cnt << endl;
    for (int i = 0; i < size.size(); i++)
        cout << size[i] << endl;

    for (int i = 0; i < N; i++)
    {
        delete[] map[i];
        delete[] visit[i];
    }
    delete[] map;
    delete[] visit;
}
void dfs(pair<int, int> p, int **map, bool **visit, vector<int> &size)
{
    visit[p.first][p.second] = true;
    size[cnt] += 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        if (map[nx][ny] == 1 && !visit[nx][ny])
            dfs(make_pair(nx, ny), map, visit, size);
    }
}