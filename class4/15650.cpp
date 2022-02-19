// 15650 N과 M(2)
#include <iostream>
#include <vector>
#define LEN 10
using namespace std;
int N, M;
void DFS(int, int, vector<int> &);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<int> arr(LEN, 0);

    DFS(1, 0, arr);
}
void DFS(int start, int cnt, vector<int> &arr)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = start; i <= N; i++)
    {
        // 오름차순으로 정렬된 수열만 출력하므로 방문 고려할 필요가 없음
        arr[cnt] = i;
        DFS(i + 1, cnt + 1, arr);
    }
}