// 1202 보석 도둑(수정중)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct jewel
{
    int m; // weight
    int v; // price
} Jewel;

struct compare
{
    bool operator()(Jewel a, Jewel b)
    {
        return a.v < b.v;
    }
};

bool findBag(int start, int end, int target, vector<int> &bag)
{
    if (start > end)
    {
        if (bag[start] <= target)
            return 1;
        else
            return 0;
    }
    int mid = (start + end) / 2;
    if (bag[mid] == target)
        return 1;
    else if (bag[mid] < target)
        return findBag(0, mid - 1, target, bag);
    else
        return findBag(mid + 1, end, target, bag);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    priority_queue<Jewel, vector<Jewel>, compare> q;
    for (int i = 0; i < N; i++)
    {
        Jewel tmp;
        cin >> tmp.m >> tmp.v;
        q.push(tmp);
    }
    vector<int> bag(K, 0);
    for (int i = 0; i < K; i++)
        cin >> bag[i];
    sort(bag.begin(), bag.end());

    int total = 0;
    for (int i = 0; i < K; i++)
    {
        Jewel target = q.top();
        q.pop();

        if (findBag(0, K - 1, target.m, bag))
            total += target.v;
    }
    cout << total;
}