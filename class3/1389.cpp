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

    //���� ���� ����
    vector<int> *data = new vector<int>[N + 1];
    // �湮 ���� Ȯ��
    int **visit;
    visit = new int *[N + 1];
    for (int i = 0; i < N + 1; i++)
        visit[i] = new int[N + 1]();
    //�ɺ� �������� �� ī����

    while (M--)
    {
        int A, B;
        cin >> A >> B;
        data[A].push_back(B); //����� ����
        data[B].push_back(A);
    }
    //���ͳ� �ߺ� �� ���� �� �������� ����
    for (int i = 1; i <= N; i++)
    {
        sort(data[i].begin(), data[i].end());
        data[i].erase(unique(data[i].begin(), data[i].end()), data[i].end());
    }
    cout << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < data[i].size(); j++)
            cout << data[i][j] << " ";
        cout << endl;
    }

    for (int i = 1; i <= N; i++)
    {
        bfs(i, data, visit[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << visit[i][j] << " ";
        cout << endl;
    }
    delete[] data;
    for (int i = 0; i < N + 1; i++)
        delete[] visit[i];
    delete[] visit;
}
void bfs(int start, vector<int> *data, int *visit)
{
    int cnt = 0;
    queue<int> q;
    q.push(start);
    visit[start] = 0;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < data[n].size(); i++)
        {
            int nn = data[n][i];
            if (visit[nn] == 0)
            {
                q.push(nn);
                visit[nn] = cnt;
            }
        }
    }
}