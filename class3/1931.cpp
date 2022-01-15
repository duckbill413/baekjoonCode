//중요도!!!
//그리디 알고리즘
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct pair
{
    int start, end;
} Pair;

struct compare
{
    bool operator()(Pair a, Pair b)
    {
        if (a.end == b.end) //종료시간이 같을 경우 빨리 시작하는 순 정렬
            return a.start > b.start;
        else //종료시간이 빠른 순 정렬
            return a.end > b.end;
    }
};

int main()
{
    //우선순위 큐를 이용하여 compare에 따라서 push해준다.
    //(종료시간이 빠른순 같을 경우 시작시간이 빠른 순)
    priority_queue<Pair, vector<Pair>, compare> q;

    int N;
    cin >> N;
    Pair in;
    while (N--)
    {
        cin >> in.start >> in.end;
        q.push(in);
    }
    int end = 0; //종료 시간
    int cnt = 0;
    //우선순위 큐이므로 이미 정렬되어져 있음
    while (q.size() > 0)
    {
        Pair out = q.top();
        q.pop();
        if (end <= out.start)
        {
            cnt++;
            end = out.end;
        }
    }

    cout << cnt;
}