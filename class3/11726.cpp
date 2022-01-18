#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int num[1001] = {0};
    num[1] = 1;
    num[2] = 2;
    for (int i = 3; i <= N; i++)
        num[i] = (num[i - 1] + num[i - 2]) % 10007;
    cout << num[N];
}