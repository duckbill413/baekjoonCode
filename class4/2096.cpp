// 2096 내려가기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> minDp(3, 0);
    vector<int> maxDp(3, 0);
    vector<int> tmp(3, 0);
    int N, a, b, c;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        if (i == 0)
        {
            minDp[0] = a;
            minDp[1] = b;
            minDp[2] = c;
            maxDp[0] = a;
            maxDp[1] = b;
            maxDp[2] = c;
            continue;
        }

        tmp[0] = a + min(minDp[0], minDp[1]);
        tmp[1] = b + min(minDp[0], min(minDp[1], minDp[2]));
        tmp[2] = c + min(minDp[1], minDp[2]);
        minDp.assign(tmp.begin(), tmp.end());

        tmp[0] = a + max(maxDp[0], maxDp[1]);
        tmp[1] = b + max(maxDp[0], max(maxDp[1], maxDp[2]));
        tmp[2] = c + max(maxDp[1], maxDp[2]);
        maxDp.assign(tmp.begin(), tmp.end());
    }

    int MaxSum = max(maxDp[0], max(maxDp[1], maxDp[2]));
    int MinSum = min(minDp[0], min(minDp[1], minDp[2]));

    cout << MaxSum << " " << MinSum;
    return 0;
}