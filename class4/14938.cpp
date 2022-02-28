// 14938 서강 그라운드
// 플로이드 마샬
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

void FloydMarshall(vector<vector<int>> &);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, R;
    cin >> N >> M >> R;
    vector<int> item(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> item[i];

    vector<vector<int>> table(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++)
        table[i][i] = 0;
    int a, b, l;
    for (int i = 1; i <= R; i++)
    {
        cin >> a >> b >> l;
        if (table[a][b] > l)
            table[a][b] = l;
        if (table[b][a] > l)
            table[b][a] = l;
    }
    FloydMarshall(table);
    int max = 0, cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        cnt = 0;
        for (int j = 1; j <= N; j++)
        {
            if (table[i][j] <= M)
            {
                cnt += item[j];
            }
        }
        if (cnt > max)
            max = cnt;
    }

    cout << max;
    return 0;
}

void FloydMarshall(vector<vector<int>> &table)
{
    int N = table.size() - 1;
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (table[i][k] != INF && table[k][j] != INF)
                {
                    table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
                }
}