//중요도!!!!
// BFS 알고리즘
#include <iostream>
#include <queue>
#define MAX_LEN 100001
using namespace std;

bool visit[MAX_LEN] = {0};
int bfs(int N, int M)
{
    int time = 0;
    queue<int> q;
    q.push(N);
    visit[N] = true;

    while (1)
    {
        int queSize = q.size();
        for (int i = 0; i < queSize; i++)
        {
            int node = q.front();
            q.pop();

            if (node == M)
                return time;
            if (node > 0 && !visit[node - 1])
            {
                q.push(node - 1);
                visit[node - 1] = true;
            }
            if (node < MAX_LEN - 1 && !visit[node + 1])
            {
                q.push(node + 1);
                visit[node + 1] = true;
            }
            if (node * 2 < MAX_LEN && !visit[node * 2])
            {
                q.push(node * 2);
                visit[node * 2] = true;
            }
        }
        time++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    cout << bfs(N, M) << endl;
    return 0;
}