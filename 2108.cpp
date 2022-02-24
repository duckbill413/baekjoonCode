// 2108 통계학
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    vector<int> count(8001, 0);
    int cnt = 0; //최빈도
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        count[arr[i] + 4000]++;
        if (count[arr[i] + 4000] > cnt)
            cnt = count[arr[i] + 4000];
    }

    sort(arr.begin(), arr.end()); //오름차순정렬
    //평균
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    int avg = floor(sum / (double)N + 0.5);
    cout << avg << '\n';

    //중앙값
    cout << arr[N / 2] << '\n';

    //최빈값
    vector<int> answer;
    for (int i = arr.front() + 4000; i <= arr.back() + 4000; i++)
    {
        if (count[i] == cnt)
            answer.push_back(i - 4000);
    }
    sort(answer.begin(), answer.end());
    if (answer.size() > 1)
        cout << answer[1] << '\n';
    else
        cout << answer[0] << '\n';
    // 범위
    cout << arr.back() - arr.front();
}