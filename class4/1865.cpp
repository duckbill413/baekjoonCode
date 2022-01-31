// 1865 ¿úÈ¦
// º§¸¸-Æ÷µå
#include <iostream>
#include <vector>
#include <tuple>
#define INF 1e9
using namespace std;
typedef tuple<int, int, int> T;
bool calcReturnTime(int N, int M, int W);
void TimeInit(vector<int> &TIME);
void BellmanFord(int start, vector<T> &MAP, vector<int> &TIME);
int main()
{
    int TC;
    int N, M, W;
    cin >> TC;
    while (TC--)
    {
        cin >> N >> M >> W;
        if (calcReturnTime(N, M, W))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}
bool calcReturnTime(int N, int M, int W)
{
    vector<T> MAP;
    vector<int> TIME(N + 1, INF);
    int S, E, T;
    for (int i = 0; i < M; i++)
    {
        cin >> S >> E >> T;
        MAP.push_back({S, E, T});
        MAP.push_back({E, S, T});
    }
    for (int i = 0; i < M; i++)
    {
        cin >> S >> E >> T;
        MAP.push_back({S, E, -T});
    }
}

void BellmanFord(int start, vector<T> &MAP, vector<int> &TIME)
{
    int N = TIME.size() - 1;
    TIME[1] = 0;

    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < MAP.size(); j++)
        {
            T cur = MAP[j];
            get<1>(cur)
        }
    }
}
void TimeInit(vector<int> &TIME)
{
    for (int i = 0; i < TIME.size(); i++)
        TIME[i] = INF;
}
