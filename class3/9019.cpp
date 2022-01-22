//중요도!!!
// BFS 알고리즘, 벡터 복사
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int DoubleNum(int num);
int SumNum(int num);
int LeftTurnNum(int num);
int RightTurnNum(int num);

int visit[10001];

void BFS(int start, int target, vector<char> *print);

int main()
{
    int T;
    cin >> T;
    int A, B;
    vector<char> *print = new vector<char>[10001];
    while (T--)
    {
        cin >> A >> B;
        BFS(A, B, print);

        for (int i = 0; i < print[B].size(); i++)
            cout << print[B][i];
        cout << '\n';
        for (int i = 0; i < 10000; i++)
            print[i].clear();
        for (int i = 0; i < 10001; i++)
            visit[i] = 0;
        print->clear();
    }
}
int DoubleNum(int num)
{
    return (num * 2) % 10000;
}
int SumNum(int num)
{
    return (num + 9999) % 10000;
}
int LeftTurnNum(int num)
{
    return num % 1000 * 10 + num / 1000;
}
int RightTurnNum(int num)
{
    return num % 10 * 1000 + num / 10;
}
void BFS(int start, int target, vector<char> *print)
{
    queue<int> q;
    visit[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int next = q.front();
        q.pop();

        int tmp = DoubleNum(next);
        if (!visit[tmp])
        {
            q.push(tmp);
            visit[tmp] = 1;
            print[tmp].assign(print[next].begin(), print[next].end());
            print[tmp].push_back('D');
            if (tmp == target)
                break;
        }
        tmp = SumNum(next);
        if (!visit[tmp])
        {
            q.push(tmp);
            visit[tmp] = 1;
            print[tmp].assign(print[next].begin(), print[next].end());
            print[tmp].push_back('S');
            if (tmp == target)
                break;
        }
        tmp = LeftTurnNum(next);
        if (!visit[tmp])
        {
            q.push(tmp);
            visit[tmp] = 1;
            print[tmp].assign(print[next].begin(), print[next].end());
            print[tmp].push_back('L');
            if (tmp == target)
                break;
        }
        tmp = RightTurnNum(next);
        if (!visit[tmp])
        {
            q.push(tmp);
            visit[tmp] = 1;
            print[tmp].assign(print[next].begin(), print[next].end());
            print[tmp].push_back('R');
            if (tmp == target)
                break;
        }
    }
}