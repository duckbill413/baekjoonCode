#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(int start, vector<int> *data, int *visit);

int main()
{
    int N, M;
    cin >> N >> M;

    //정점 벡터 생성
    vector<int> *data = new vector<int>[N + 1];
    // 방문 여부 확인
    int **visit;
    visit = new int *[N + 1];
    for (int i = 0; i < N + 1; i++)
        visit[i] = new int[N + 1]();
    //케빈 베이컨의 수 카운팅

    while (M--)
    {
        int A, B;
        cin >> A >> B;
        data[A].push_back(B); //양방향 연결
        data[B].push_back(A);
    }
    //벡터내 중복 값 제거 및 오름차순 정렬
    for (int i = 1; i <= N; i++)
    {
        sort(data[i].begin(), data[i].end());
        data[i].erase(unique(data[i].begin(), data[i].end()), data[i].end());
    }

    for (int i = 1; i <= N; i++)
        bfs(i, data, visit[i]);

    int *sum = new int[N + 1]();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // cout << visit[i][j] << " ";
            sum[i] += visit[i][j];
        }
        // cout << "  sum: " << sum[i];
        // cout << endl;
    }
    int min, minIdx;
    for (int i = 1; i <= N; i++)
    {
        if (min > sum[i] || i == 1)
        {
            min = sum[i];
            minIdx = i;
        }
    }
    cout << minIdx << endl;

    delete[] data;
    for (int i = 0; i < N + 1; i++)
        delete[] visit[i];
    delete[] visit;
    delete[] sum;
}
void bfs(int start, vector<int> *data, int *visit)
{
    queue<int> q;
    q.push(start);
    visit[start] = 0;

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        for (int i = 0; i < data[n].size(); i++)
        {
            int nn = data[n][i];
            if (visit[nn] == 0 && nn != start)
            {
                q.push(nn);
                visit[nn] = visit[n] + 1;
            }
        }
    }
}