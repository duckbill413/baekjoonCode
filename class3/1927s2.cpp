//중요도!!!!!
//우선순위 큐(우선순위 힙)
// C++로 구현 queue 헤더 사용
#include <iostream>
#include <queue>
#define endl "\n";
#define QUE_LEN 100002
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> minQue; //최소정렬 힙
    int N;
    cin >> N;
    while (N--)
    {
        int tmp;
        cin >> tmp;

        if (tmp == 0)
        {
            if (minQue.empty())
            {
                cout << "0" << endl;
            }
            else
            {
                cout << minQue.top() << endl;
                minQue.pop();
            }
        }
        else
            minQue.push(tmp);
    }
}