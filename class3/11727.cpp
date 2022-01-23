// 2xn ≈∏¿œ∏µ 2
#include <iostream>
using namespace std;
int main()
{
    int DP[1001] = {0};
    int N;
    cin >> N;
    DP[1] = 1;
    DP[2] = 3;
    for (int i = 3; i <= N; i++)
        DP[i] = (DP[i - 1] + 2 * DP[i - 2]) % 10007;

    cout << DP[N];
}