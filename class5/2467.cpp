// 2467 용액
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int FindNearest(int target, vector<int> &arr, int start, int end);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int a, b;
    int left = 0, right = N - 1, sum = 2000000002;
    while (left < right)
    {
        int tmp = arr[left] + arr[right];
        if (abs(sum) > abs(tmp))
        {
            a = arr[left];
            b = arr[right];
            sum = tmp;
        }

        if (tmp > 0)
            right--;
        else
            left++;
    }

    printf("%d %d", a, b);
    return 0;
}
