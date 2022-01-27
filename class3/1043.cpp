#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> trueth(N);
    vector<vector<int>> party(M + 1, vector<int>());

    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> trueth[i];

    for (int i = 1; i <= M; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }
        sort(party[i].begin(), party[i].end());
    }
}