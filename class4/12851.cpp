// 13549 숨바꼭질2
#include <iostream>
#include <vector>
#include <queue>
#define SIZE 100001
using namespace std;
void Find(int, int, vector<int> &, vector<int> &);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> visited(SIZE, -1);
    vector<int> cnt(SIZE, 0);
    Find(N, K, visited, cnt);

    cout << visited[K] << '\n';
    cout << cnt[K];
}
void Find(int start, int target, vector<int> &visited, vector<int> &cnt)
{
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    cnt[start] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : {cur * 2, cur + 1, cur - 1})
        {
            if (next >= 0 && next < SIZE)
            {
                if (visited[next] == -1)
                {
                    visited[next] = visited[cur] + 1;
                    cnt[next] = cnt[cur];
                    q.push(next);
                }
                else if (visited[next] == visited[cur] + 1)
                    cnt[next] += cnt[cur];
            }
        }
    }
}
int inRange(int idx)
{
    if (idx >= 0 && idx < SIZE)
        return 1;
    return 0;
}