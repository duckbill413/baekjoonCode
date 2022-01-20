#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main()
{

    int T, n;
    cin >> T;
    string p;      //명령어
    string numStr; //문자열로 이루어진 정수 집합

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
            if (numStr[i] >= '0' && numStr[i] <= '9') //문자형 정수
                tmp = tmp * 10 + (numStr[i] - '0');
            else if (tmp > 0) // num에 tmp가 0인 경우가 들어가지 않게 하기 위함
            {
                num.push_back(tmp);
                tmp = 0; // tmp 초기화
            }
        }

        int flag = 0; // flag : 0 순차, 1 역순, 3 에러
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'D' && num.empty()) // D이면서 큐가 비었다면 에러
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
                if (flag == 0) //순차
                {
                    cout << num.front();
                    num.pop_front();
                    if (num.size() != 0)
                        cout << ",";
                }
                else if (flag == 1) //역순
                {
                    cout << num.back();
                    num.pop_back();
                    if (num.size() != 0)
                        cout << ",";
                }
            }
            cout << "]" << endl;
        }
        else //에러 확인
            cout << "error" << endl;

        p.clear();
        numStr.clear();
        num.clear();
    }
}