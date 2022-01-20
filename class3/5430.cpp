#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main()
{

    int T, n;
    cin >> T;
    string p;      //��ɾ�
    string numStr; //���ڿ��� �̷���� ���� ����

    deque<int> num;

    while (T--)
    {
        cin.ignore();
        cin >> p;
        cin >> n;
        cin.ignore();
        cin >> numStr;

        int tmp = 0;
        for (int i = 1; i < numStr.size(); i++)
        {
            if (numStr[i] >= '0' && numStr[i] <= '9') //������ ����
                tmp = tmp * 10 + (numStr[i] - '0');
            else if (tmp > 0) // num�� tmp�� 0�� ��찡 ���� �ʰ� �ϱ� ����
            {
                num.push_back(tmp);
                tmp = 0; // tmp �ʱ�ȭ
            }
        }

        int flag = 0; // flag : 0 ����, 1 ����, 3 ����
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'D' && num.empty()) // D�̸鼭 ť�� ����ٸ� ����
            {
                flag = 3;
                break;
            }
            if (p[i] == 'R' && flag == 0)
                flag = 1;
            else if (p[i] == 'R' && flag == 1)
                flag = 0;
            else if (p[i] == 'D' && flag == 0)
                num.pop_front();
            else if (p[i] == 'D' && flag == 1)
                num.pop_back();
        }

        if (flag != 3)
        {
            cout << "[";
            while (!num.empty())
            {
                if (flag == 0) //����
                {
                    cout << num.front();
                    num.pop_front();
                    if (num.size() != 0)
                        cout << ",";
                }
                else if (flag == 1) //����
                {
                    cout << num.back();
                    num.pop_back();
                    if (num.size() != 0)
                        cout << ",";
                }
            }
            cout << "]" << endl;
        }
        else //���� Ȯ��
            cout << "error" << endl;

        p.clear();
        numStr.clear();
        num.clear();
    }
}