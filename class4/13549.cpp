// 13549 ¼û¹Ù²ÀÁú
#include <iostream>
#include <vector>
#include <queue>
#define SIZE 100002
using namespace std;

void Find(int, int, vector<int> &);
int inRange(int);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> visited(SIZE, -1);

    Find(N, K, visited);

    cout << visited[K];
}
void Find(int start, int target, vector<int> &visited)
{
    queue<int> q;
    visited[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == target)
            break;

        int next = cur * 2;
        if (inRange(next) && visited[next] == -1)
        {
            visited[next] = visited[cur];
            q.push(next);
        }
        next = cur - 1;
        if (inRange(next) && visited[next] == -1)
        {
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
        next = cur + 1;
        if (inRange(next) && visited[next] == -1)
        {
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
}
int inRange(int idx)
{
    if (idx >= 0 && idx < SIZE)
        return 1;
    return 0;
}