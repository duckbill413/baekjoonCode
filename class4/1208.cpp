// 1208 부분수열의 합
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, S;
long long cnt;
map<int, int> sumIdx;
vector<int> arr;

void leftSeq(int start, int sum);
void rightSeq(int mid, int sum);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cnt = 0;
    leftSeq(0, 0);
    rightSeq(N / 2, 0);
    if (S == 0)
        cnt--;
    cout << cnt;
}
void leftSeq(int start, int sum)
{
    if (start == N / 2)
    {
        sumIdx[sum]++;
        return;
    }
    leftSeq(start + 1, sum);
    leftSeq(start + 1, sum + arr[start]);
}
void rightSeq(int mid, int sum)
{
    if (mid == N)
    {
        cnt += sumIdx[S-sum];
        return;
    }
    rightSeq(mid + 1, sum);
    rightSeq(mid + 1, sum + arr[mid]);
}