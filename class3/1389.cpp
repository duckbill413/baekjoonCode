#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N, M;

    //���� ���� ����
    vector<int> *data = new vector<int>[N + 1];
    // �湮 ���� Ȯ��
    bool **visit;
    visit = new bool *[N + 1];
    for (int i = 0; i < N + 1; i++)
        visit[i] = new bool[N + 1]();
    //�ɺ� �������� �� ī����
    int **cnt;
    cnt = new int *[N + 1];
    for (int i = 0; i < N + 1; i++)
        cnt[i] = new cnt[N + 1]();

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
}