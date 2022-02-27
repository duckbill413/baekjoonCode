// 11404 플로이드
// 중요도!!!!!
// 플로이드 마샬 알고리즘
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

    int N, M;
    cin >> N >> M;
    vector<vector<int>> table(N + 1, vector<int>(N + 1, INF));

    int s, e, c;
    for (int i = 1; i <= M; i++)
    {
        cin >> s >> e >> c;
        if (table[s][e] > c)
            table[s][e] = c;
    }
    FloydMarshall(table);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (i == j || table[i][j] == INF)
                cout << "0 ";
            else
                cout << table[i][j] << " ";
        cout << '\n';
    }
}
void FloydMarshall(vector<vector<int>> &table)
{
    int N = table.size() - 1;
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (table[i][k] != INF && table[k][j])
                    table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
}