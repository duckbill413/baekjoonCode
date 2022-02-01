// 1865 ¿úÈ¦
// º§¸¸-Æ÷µå
#include <iostream>
#include <vector>
#include <tuple>
#define INF 987654321
using namespace std;
typedef tuple<int, int, int> T;
bool calcReturnTime(int N, int M, int W);
bool BellmanFord(vector<T> &MAP, vector<int> &TIME);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
    vector<int> TIME(N + 1, 0);
    int S, E, T;
    for (int i = 0; i < M; i++)
    {
        cin >> S >> E >> T;
        MAP.push_back({S, E, T});
        MAP.push_back({E, S, T});
    }
    for (int i = 0; i < W; i++)
    {
        cin >> S >> E >> T;
        MAP.push_back({S, E, -T});
    }

    return BellmanFord(MAP, TIME);
}

bool BellmanFord(vector<T> &MAP, vector<int> &TIME)
{
    int N = TIME.size() - 1;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < MAP.size(); j++)
        {
            // T : <0> start, <1> end, <2> time
            int s, e, t;
            tie(s, e, t) = MAP[j];
            if (TIME[s] == INF)
                continue;
            if (TIME[s] + t < TIME[e])
                TIME[e] = TIME[s] + t;
        }
    }
    for (int i = 0; i < MAP.size(); i++)
    {
        int s, e, t;
        tie(s, e, t) = MAP[i];
        if (TIME[s] == INF)
            continue;
        if (TIME[s] + t < TIME[e])
            return true; // time goes to minus forever(return to start point)
    }
    return false;
}