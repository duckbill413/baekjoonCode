// 16953 A -> B
// BFS 실행시 메모리 초과로 잘 작동되지 않았다
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    ll A, B;
    cin >> A >> B;
    int ans = -1;

    queue<pair<int, int>> q;
    // q.first 에 좌표값, q.second에 cost 저장
    q.push({A, 1});
    while (!q.empty())
    {
        pair<ll, int> cur = q.front();
        q.pop();

        if (cur.first == B)
        {
            ans = cur.second;
            break;
        }

        if (cur.first * 2 <= B)
            q.push({cur.first * 2, cur.second + 1});
        if (cur.first * 10 + 1 <= B)
            q.push({cur.first * 10 + 1, cur.second + 1});
    }
    cout << ans;
}