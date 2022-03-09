// 1202 보석 도둑
// 작은 가방에 최대한 가치가 큰 보석을 담아야 한다.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<P> jewel(N);
    for (int i = 0; i < N; i++)
    {
        int m, v;
        cin >> m >> v; // m은 무게, v는 가격
        jewel[i] = make_pair(m, v);
    }
    sort(jewel.begin(), jewel.end()); //보석 무게를 기준으로 오름차순 정렬
    vector<int> bag(K);
    for (int i = 0; i < K; i++)
        cin >> bag[i];
    sort(bag.begin(), bag.end()); // 가방 오름차순 정렬

    long long result = 0;
    priority_queue<int> pq; //가치가 큰 순서로 저장
    int idx = 0;
    for (int i = 0; i < K; i++)
    {
        while (idx < N && jewel[idx].first <= bag[i])
            pq.push(jewel[idx++].second);

        if (!pq.empty()) //가방에는 한개의 보석만 담을 수 있다.
        {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;
}