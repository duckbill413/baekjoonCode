// 1149 RGB거리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// NOTE: 0: default, 1: red, 2: green 3: blue
int Price(vector<int> house, int &color);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int r, g, b;
    cin >> N;
    vector<int> DP(N + 1, 0);
    vector<vector<int>> house(N + 1, vector<int>(3, 0));
    for (int i = 1; i <= N; i++)
    {
        cin >> r >> g >> b;
        // NOTE: 빨강, 초록, 파랑으로 칠하였을떄의 최솟값을 각각 저장 해준다.
        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + r;
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + g;
        house[i][2] = min(house[i - 1][0], house[i - 1][1]) + b;
    }
    cout << min(house[N][0], min(house[N][1], house[N][2]));
}