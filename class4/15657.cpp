// 15652 N과 M (8)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> print(9, 0);
void printNumber();
void DFS(int idx, int cnt, int target, vector<int> &num, vector<int> &visited);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<int> num(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    vector<int> visited(N + 1, 0);
    sort(num.begin(), num.end());
    DFS(1, 0, M, num, visited);
}
void printNumber()
{
    for (int i = 0; i < M; i++)
        cout << print[i] << " ";
    cout << '\n';
}
void DFS(int idx, int cnt, int target, vector<int> &num, vector<int> &visited)
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
        print[cnt] = num[i];
        DFS(i, cnt + 1, target, num, visited);
        visited[i] = 0;
    }
}