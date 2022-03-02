// 1806 부분합
// 중요도!!!
// 투 포인터
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, S;
    cin >> N >> S;
    vector<int> num(N, 0);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    int s = 0, e = 0, sum = 0, len = 100001;
    while (s <= e)
    {
        if (sum >= S)
        {
            len = min(len, e - s);
            sum -= num[s++];
        }
        else if (e == N)
            break;
        else
            sum += num[e++];
    }
    if (len == 100001)
        cout << 0;
    else
        cout << len;
}