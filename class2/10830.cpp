// 10830 행렬 제곱
// 중요도!!!!
// 분할 정복을 이용한 행렬 제곱
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000;

vector<vector<int>> powMatrix(vector<vector<int>>, long long);
vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B);
int main()
{
    int N;
    long long B;
    cin >> N >> B;
    vector<vector<int>> matrix(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> matrix[i][j];

    vector<vector<int>> ret = powMatrix(matrix, B);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << ret[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
vector<vector<int>> powMatrix(vector<vector<int>> matrix, long long B)
{
    if (B <= 1)
    {
        for (int i = 1; i < matrix.size(); i++)
            for (int j = 1; j < matrix.size(); j++)
                matrix[i][j] %= MOD;
        return matrix;
    }

    // 지수를 절반으로 하여 분할하고 재귀 함수 호출
    vector<vector<int>> ret = powMatrix(matrix, B / 2);

    ret = multiply(ret, ret);

    // 지수가 홀수일 경우 초기 행렬을 곱한다.
    if (B % 2)
        ret = multiply(ret, matrix);

    return ret;
}
vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int N = A.size() - 1;
    vector<vector<int>> ret(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
            {
                ret[i][j] += A[i][k] * B[k][j];
                ret[i][j] %= MOD;
            }

    return ret;
}