//중요도!!
// DFS알고리즘
#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, vector<int> *map, bool *visit);
int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> *map = new vector<int>[N + 1];
    bool *visit = new bool[N + 1]();

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        map[A].push_back(B);
        map[B].push_back(A);
    }
    int cnt = 0;
    for (int i = 1; i < N + 1; i++)
    {
        if (!visit[i])
        {
            dfs(i, map, visit);
            cnt++;
        }
    }
    cout << cnt;

    delete[] map;
    delete[] visit;
    return 0;
}
void dfs(int start, vector<int> *map, bool *visit)
{
    visit[start] = true;
    for (int i = 0; i < map[start].size(); i++)
    {
        int next = map[start][i];
        if (!visit[next])
            dfs(next, map, visit);
    }
}