// 9663 N-Queen
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;
int N;
int ans;

void DFS(int start, vector<int> &st, vector<int> &c1, vector<int> &c2);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    vector<int> st(N, 0);
    vector<int> cross1(2 * N, 0), cross2(2 * N, 0);
    DFS(0, st, cross1, cross2);
    cout << ans;
    return 0;
}
void DFS(int start, vector<int> &st, vector<int> &c1, vector<int> &c2)
{
    if (start == N)
    {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (st[i] == 0 && c1[start + i] == 0 && c2[start - i + N] == 0)
        {
            st[i] = 1; //세로 방향 탐색
            c1[start + i] = c2[start - i + N] = 1;
            DFS(start + 1, st, c1, c2);
            st[i] = 0;
            c1[start + i] = c2[start - i + N] = 0;
        }
    }
}