// 2407 조합
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string ans[101][101];

string addNum(string num1, string num2)
{
    int len;
    if (num1.length() > num2.length())
    {
        while (num1.length() > num2.length())
            num2 = '0' + num2;
    }
    else
    {
        while (num1.length() < num2.length())
            num1 = '0' + num1;
    }
    len = num1.length();

    string result = "";
    int tmp = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        tmp += (num1[i] - '0') + (num2[i] - '0');
        result = to_string(tmp % 10) + result;
        if (tmp >= 10)
            tmp = 1;
        else
            tmp = 0;
    }
    if (tmp == 1)
        return '1' + result;
    else
        return result;
}
void Calc(int N, int M)
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i == j || j == 0)
                ans[i][j] = "1";
            else
                ans[i][j] = addNum(ans[i - 1][j - 1], ans[i - 1][j]);
        }
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    ans[0][0] = "1";
    ans[1][0] = ans[1][1] = "1"; //초기값 설정
    Calc(N, M);
    cout << ans[N][M];
}