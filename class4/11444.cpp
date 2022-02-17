// 11444 피보나치 수 6
#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

void multi(vector<vector<long long>> &mat1, vector<vector<long long>> &mat2)
{
    vector<vector<long long>> tmp(2, vector<long long>(2, 0));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                tmp[i][j] += ((mat1[i][k] * mat2[k][j]) % MOD);
            }
            tmp[i][j] %= MOD;
        }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            mat1[i][j] = tmp[i][j];
}
int main()
{
    vector<vector<long long>> ans = {{1, 0}, {0, 1}};
    vector<vector<long long>> matrix = {{1, 1}, {1, 0}};

    long long N;
    cin >> N;

    while (N > 0)
    {
        if (N % 2)
            multi(ans, matrix);

        multi(matrix, matrix);
        N /= 2;
    }

    cout << ans[0][1];
}