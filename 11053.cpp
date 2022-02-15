// 11053 가장 긴 증가하는 부분 수열
#include <iostream>
#include <vector>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

int FindLongest(vector<int> &nums, vector<int> &DP)
{
    int ans = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                DP[i] = MAX(DP[i], DP[j] + 1);
            }
        }
        ans = MAX(ans, DP[i]);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> nums(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> nums[i];

    vector<int> DP(N + 1, 1);
    cout << FindLongest(nums, DP);
    return 0;
}