// 1629 °ö¼À
// BUG: ¸Þ¸ð¸® ÃÊ°ú ¹ß»ý
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    vector<int> MOD(1, 0);

    long long num = A;
    MOD.push_back(A % C); // A%C
    for (int i = 2; i <= B; i++)
    {
        num *= A;
        num %= C;
        if (num == MOD[1])
            break;
        else
            MOD.push_back(num);
    }
    int idx = B % (MOD.size() - 1);
    idx = idx == 0 ? MOD.size() - 1 : idx;
    cout << MOD[idx];
}