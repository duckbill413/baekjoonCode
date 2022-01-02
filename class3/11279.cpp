#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> maxQue;
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 0)
        {
            if (maxQue.empty())
                printf("0\n");
            else
            {
                printf("%d\n", maxQue.top());
                maxQue.pop();
            }
        }
        else
            maxQue.push(tmp);
    }
}