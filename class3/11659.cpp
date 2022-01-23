#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> num;
    vector<int> sum(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            sum[i + 1] = num[i];
        else
            sum[i + 1] = sum[i] + num[i];
    }
    while (M--)
    {
        int start, end;
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << '\n';
    }
}