// 15663 N과 M (9)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> print(9, 0);
void printNumber();
void DFS(int cnt, int target, vector<int> &num, vector<int> &visited);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<int> arr(N + 1, 0);
    vector<int> visited(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    DFS(0, M, arr, visited);
}
void printNumber()
{
    for (int i = 0; i < M; i++)
        cout << print[i] << " ";
    cout << '\n';
}
void DFS(int cnt, int target, vector<int> &num, vector<int> &visited)
{
    if (cnt == target)
    {
        printNumber();
        return;
    }
    int fin = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 1 || num[i] == fin)
            continue;
        visited[i] = 1;
        print[cnt] = num[i];
        fin = num[i];
        DFS(cnt + 1, target, num, visited);
        visited[i] = 0;
    }
}