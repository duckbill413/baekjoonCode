#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, K;
    vector<int> coin;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        coin.push_back(tmp);
    }
    int cnt = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (coin[i] <= K)
        {
            cnt += K / coin[i];
            K %= coin[i];
        }
        if (K == 0)
            break;
    }
    cout << cnt;
}