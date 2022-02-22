// 11054 가장 긴 바이토닉 부분 수열
// 가장 긴 증가하는 부분 수열과 가장 긴 감소하는 부분 수열로 나누어 생각
#include <iostream>
#include <vector>
using namespace std;

void getDP(vector<int> &arr, vector<vector<int>> &DP)
{
    int N = arr.size() - 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j] && DP[i][0] < DP[j][0] + 1)
                DP[i][0] = DP[j][0] + 1;
        }
    }

    for (int i = N; i >= 1; i--)
    {
        for (int j = N; j > i; j--)
        {
            if (arr[i] > arr[j] && DP[i][1] < DP[j][1] + 1)
                DP[i][1] = DP[j][1] + 1;
        }
    }
}
int main()
{
    int N;
    cin >> N;

    vector<int> arr(N + 1, 0);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    vector<vector<int>> DP(N + 1, vector<int>(2, 1));
    getDP(arr, DP);
    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        int tmp = DP[i][0] + DP[i][1];
        if (tmp > max)
            max = tmp;
    }

    cout << max - 1;
}