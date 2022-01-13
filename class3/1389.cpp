#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N, M;

    //정점 벡터 생성
    vector<int> *data = new vector<int>[N + 1];
    // 방문 여부 확인
    bool **visit;
    visit = new bool *[N + 1];
    for (int i = 0; i < N + 1; i++)
        visit[i] = new bool[N + 1]();
    //케빈 베이컨의 수 카운팅
    int **cnt;
    cnt = new int *[N + 1];
    for (int i = 0; i < N + 1; i++)
        cnt[i] = new cnt[N + 1]();

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
}