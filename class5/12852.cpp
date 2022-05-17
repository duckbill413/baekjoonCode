#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int main()
{
    int X;
    cin >> X;

    for (int i = 1; i <= X; i++)
        dp[i] = i;

    for (int i = 2; i <= X; i++)
    {
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3]);
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2]);
        dp[i] = min(dp[i], dp[i - 1]) + 1;
    }

    cout << dp[X] - 1 << '\n';

    while (X != 0)
    {
        cout << X << ' ';

        if (X % 3 == 0 && dp[X] == dp[X / 3] + 1)
            X /= 3;
        else if (X % 2 == 0 && dp[X] == dp[X / 2] + 1)
            X /= 2;
        else if (dp[X] == dp[X - 1] + 1)
            X = X - 1;
    }
}