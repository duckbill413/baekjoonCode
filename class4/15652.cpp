// 15652 N과 M (4)
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> print(9, 0);
void printNumber();
void DFS(int idx, int cnt, int target, vector<int> &visited);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<int> visited(N + 1, 0);
    DFS(1, 0, M, visited);
}
void printNumber()
{
    for (int i = 0; i < M; i++)
        cout << print[i] << " ";
    cout << '\n';
}
void DFS(int idx, int cnt, int target, vector<int> &visited)
{
    if (cnt == target)
    {
        printNumber();
        return;
    }

    for (int i = idx; i <= N; i++)
    {
        if (visited[i] == 1 && i != idx)
            continue;
        visited[i] = 1;
        print[cnt] = i;
        DFS(i, cnt + 1, target, visited);
        visited[i] = 0;
    }
}