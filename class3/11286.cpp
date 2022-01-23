#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        int absa = abs(a); // a, b의 절댓값
        int absb = abs(b);
        if (absa > absb) //절댓값에 대한 오름차순
            return true; //앞의 값이 큰 경우 swap 시켜 주어 정렬
        else if (absa < absb)
            return false;
        else //절댓값이 같은 경우 값이 크기에 대한 오름차순 정렬
        {
            if (a > b)
                return true;
            else
                return false;
        }
    }
};
int main()
{
    priority_queue<int, vector<int>, compare> pq;
    vector<int> result;
    int N;
    cin >> N;
    while (N--)
    {
        int tmp;
        cin >> tmp;
        if (tmp != 0)
            pq.push(tmp);
        else
        {
            if (pq.empty())
                result.push_back(0);
            else
            {
                result.push_back(pq.top());
                pq.pop();
            }
        }
    }
    for (auto i : result)
        cout << i << '\n';
}