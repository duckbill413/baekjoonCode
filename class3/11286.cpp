#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        int absa = abs(a); // a, b�� ����
        int absb = abs(b);
        if (absa > absb) //���񰪿� ���� ��������
            return true; //���� ���� ū ��� swap ���� �־� ����
        else if (absa < absb)
            return false;
        else //������ ���� ��� ���� ũ�⿡ ���� �������� ����
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