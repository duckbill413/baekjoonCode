#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> q;
    while (N--)
    {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    int total = 0, sum = 0;
    while (!q.empty())
    {
        sum += q.top();
        q.pop();
        total += sum;
    }
    cout << total;
}