// 15666 N과 M (12)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> print(9, 0);
void printNumber();
void DFS(int idx, int cnt, int target, vector<int> &num);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<int> arr(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    DFS(1, 0, M, arr);
}
void printNumber()
{
    for (int i = 0; i < M; i++)
        cout << print[i] << " ";
    cout << '\n';
}
void DFS(int idx, int cnt, int target, vector<int> &num)
{
    if (cnt == target)
    {
        printNumber();
        return;
    }
    int fin = 0;
    for (int i = idx; i <= N; i++)
    {
        if (num[i] == fin)
            continue;
        print[cnt] = num[i];
        fin = num[i];
        DFS(i, cnt + 1, target, num);
    }
}