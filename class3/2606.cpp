//중요도!!!
// DFS알고리즘
#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, vector<int> *node, int *visit);

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> *node = new vector<int>[N + 1];
    int *visit = new int[N + 1]();

    while (M--)
    {
        int A, B;
        cin >> A >> B;
        node[A].push_back(B);
        node[B].push_back(A);
    }

    dfs(1, node, visit);

    int cnt = 0;
    for (int i = 2; i < N + 1; i++)
    {
        if (visit[i])
            cnt++;
    }
    cout << cnt;

    delete[] node;
    delete[] visit;
}
void dfs(int start, vector<int> *node, int *visit)
{
    visit[start] = 1;
    for (int i = 0; i < node[start].size(); i++)
    {
        int next = node[start][i];
        if (!visit[next])
            dfs(next, node, visit);
    }
}