// 15652 N과 M (4)
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> print(9, 0);
void printNumber();
void DFS(int idx, int cnt, int target);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    DFS(1, 0, M);
}
void printNumber()
{
    for (int i = 0; i < M; i++)
        cout << print[i] << " ";
    cout << '\n';
}
void DFS(int idx, int cnt, int target)
{
    if (cnt == target)
    {
        printNumber();
        return;
    }
    for (int i = idx; i <= N; i++)
    {
        print[cnt] = i;
        DFS(i, cnt + 1, target);
    }
}