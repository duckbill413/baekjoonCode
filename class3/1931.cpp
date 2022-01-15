//�߿䵵!!!
//�׸��� �˰���
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
        if (a.end == b.end) //����ð��� ���� ��� ���� �����ϴ� �� ����
            return a.start > b.start;
        else //����ð��� ���� �� ����
            return a.end > b.end;
    }
};

int main()
{
    //�켱���� ť�� �̿��Ͽ� compare�� ���� push���ش�.
    //(����ð��� ������ ���� ��� ���۽ð��� ���� ��)
    priority_queue<Pair, vector<Pair>, compare> q;

    int N;
    cin >> N;
    Pair in;
    while (N--)
    {
        cin >> in.start >> in.end;
        q.push(in);
    }
    int end = 0; //���� �ð�
    int cnt = 0;
    //�켱���� ť�̹Ƿ� �̹� ���ĵǾ��� ����
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