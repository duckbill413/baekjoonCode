// 17626 Four Squares
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> DP(n + 1);
    DP[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        DP[i] = DP[i - 1] + 1;
        for (int j = 2; j * j <= i; j++)
            DP[i] = min(DP[i], 1 + DP[i - j * j]);
    }

    cout << DP[n];
}