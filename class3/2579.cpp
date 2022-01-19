#include <iostream>
#define endl "\n"
using namespace std;

int Big(int A, int B) { return A > B ? A : B; }
void Count(int N, int *stair, int *total);

int main()
{
    int N;
    cin >> N;
    int *stair = new int[N + 1];
    int *total = new int[N + 1];
    for (int i = 1; i <= N; i++)
        cin >> stair[i];

    Count(N, stair, total);

    cout << total[N];
    delete[] stair;
    delete[] total;
    return 0;
}
void Count(int N, int *stair, int *total)
{
    total[1] = stair[1];
    total[2] = stair[1] + stair[2];
    total[3] = Big(stair[1] + stair[3], stair[2] + stair[3]);

    for (int i = 4; i <= N; i++)
        total[i] = stair[i] + Big(total[i - 2], total[i - 3] + stair[i - 1]);
}