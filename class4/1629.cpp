// 1629 곱셈
// 분할정복을 이용한 거듭제곱
#include <iostream>
using namespace std;

int multi(int A, int B, int C)
{
    if (B == 1)
        return A % C;

    long long result = multi(A, B / 2, C);

    if (B % 2)
        return (result * result) % C * A % C;
    else
        return (result * result) % C;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << multi(A, B, C);
}