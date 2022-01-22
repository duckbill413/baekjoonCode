#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int gcd(int num1, int num2)
{
    while (num2 != 0)
    {
        int tmp = num1 % num2;
        num1 = num2;
        num2 = tmp;
    }
    return num1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, M, N, x, y;
    cin >> T;

    queue<int> dy;
    while (T--)
    {
        cin >> M >> N >> x >> y;
        int lcm = (M * N) / gcd(M, N);
        int tmp = y;
        while (tmp <= lcm)
        {
            dy.push(tmp);
            tmp += N;
        }

        int found = 0;
        tmp = x;
        while (tmp <= lcm)
        {
            if (tmp > dy.front())
                dy.pop();
            else if (tmp < dy.front())
                tmp += M;
            else if (tmp == dy.front())
            {
                cout << tmp << '\n';
                found = 1;
                break;
            }
            if (dy.empty())
                break;
        }
        if (!found)
            cout << "-1" << '\n';

        while (!dy.empty())
            dy.pop();
    }
}