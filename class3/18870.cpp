#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> p(N);
    vector<int> np(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
        np[i] = p[i];
    }

    //중복값 제거
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    for (int i = 0; i < N; i++)
    {
        int idx = lower_bound(p.begin(), p.end(), np[i]) - p.begin();
        cout << idx << " ";
    }
}