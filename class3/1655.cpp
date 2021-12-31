//�߿䵵!!!!
//�켱���� ť
//�߰��� ��½� �� Ȯ�� ���� ����ϱ� ���Ͽ� �߰����� �������� max, min�� queue�� ������ ����
#include <iostream>
#include <queue>
#define endl "\n";
#define QUE_LEN 100002
using namespace std;
void showMidinQue(int *arr, int N);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    showMidinQue(arr, N);
    delete[] arr;
}
void showMidinQue(int *arr, int N)
{
    priority_queue<int> maxQue;                            //�������� ����
    priority_queue<int, vector<int>, greater<int>> minQue; //�������� ����

    for (int i = 0; i < N; i++)
    {
        if (maxQue.size() > minQue.size())
            minQue.push(arr[i]);
        else
            maxQue.push(arr[i]);

        if (!maxQue.empty() && !minQue.empty())
        {
            if (maxQue.top() > minQue.top())
            {
                int maxTemp = maxQue.top();
                int minTemp = minQue.top();
                maxQue.pop();
                minQue.pop();
                maxQue.push(minTemp);
                minQue.push(maxTemp);
            }
        }
        cout << maxQue.top() << endl;
    }
}