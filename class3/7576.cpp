//�߿䵵!!!!
// BFS ���� ����
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

//�����¿�
const int dx[] = {-1, 1, 0, 0}; //����
const int dy[] = {0, 0, -1, 1}; //����
int N, M;                       // N�� ����, M�� ����

//�ּ� �ϼ��� ���ϹǷ� BFS �˰��� �̿�
void BFS(int **map, int **visit);
void setQue(queue<pair<int, int>> *q, int **map, int **visit);
int main()
{
    cin >> M >> N;

    //�丶���� Map�� �湮���ι� ���� Ȯ���ϴ� visit ����
    int **map = new int *[N];
    for (int i = 0; i < N; i++)
        map[i] = new int[M];

    int **visit = new int *[N];
    for (int i = 0; i < N; i++)
        visit[i] = new int[M]();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    BFS(map, visit);
    int Time = -1;
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] != -1 && visit[i][j] > Time)
            {
                Time = visit[i][j];
            }
            if (map[i][j] != -1 && visit[i][j] == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
        cout << -1;
    else
        cout << Time - 1;

    for (int i = 0; i < N; i++)
    {
        delete[] map[i];
        delete[] visit[i];
    }
    delete[] map;
    delete[] visit;
}
void setQue(queue<pair<int, int>> *q, int **map, int **visit)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
            {
                visit[i][j] = 1;
                q->push(make_pair(i, j));
            }
        }
}
void BFS(int **map, int **visit)
{
    queue<pair<int, int>> q;
    setQue(&q, map, visit);
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ((nx >= 0 && ny >= 0) && (nx < N && ny < M) && map[nx][ny] == 0 && visit[nx][ny] == 0)
            {
                q.push(make_pair(nx, ny));
                visit[nx][ny] = visit[x][y] + 1;
            }
        }
    }
}