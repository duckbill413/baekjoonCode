#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> result;
    int T, N;
    result.push_back(1);
    result.push_back(1);
    result.push_back(1);

    cin >> T;
    int k = 3;
    while (T--)
    {
        cin >> N;

        while (k < N)
        {
            result.push_back(result[k - 2] + result[k - 3]);
            k++;
        }

        cout << result[N - 1] << '\n';
    }
}