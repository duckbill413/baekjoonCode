// 15654 N°ú M (5)
#include <iostream>
#include <vector>
#include <algorithm>
#define LEN 10
using namespace std;
void DFS(int cnt, vector<int> &arr, vector<int> &visited, vector<int> &ans);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> arr(N, 0);
    vector<int> visited(N, 0);
    vector<int> ans(M, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    DFS(0, arr, visited, ans);
}
void DFS(int cnt, vector<int> &arr, vector<int> &visited, vector<int> &ans)
{
    if (cnt == ans.size())
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            ans[cnt] = arr[i];
            DFS(cnt + 1, arr, visited, ans);
            visited[i] = 0;
        }
    }
}