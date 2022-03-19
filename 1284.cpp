// 1284 집 주소
#include <iostream>
using namespace std;

int range(int num)
{
    int ans = 2;
    while (num)
    {
        int tmp = num % 10;
        if (tmp == 1)
            ans += 2;
        else if (tmp == 0)
            ans += 4;
        else
            ans += 3;
        num /= 10;
        if (num != 0)
            ans++;
    }
    return ans;
}
int main()
{
    int N;
    while (1)
    {
        cin >> N;
        if (N == 0)
            break;

        cout << range(N) << '\n';
    }
}