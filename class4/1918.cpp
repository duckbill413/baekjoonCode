// 1918 후위 표기식
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            cout << str[i];
        else
        {
            if (str[i] == '(')
                s.push(str[i]);
            else if (str[i] == '*' || str[i] == '/')
            {
                while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
            else if (str[i] == '+' || str[i] == '-')
            {
                while (!s.empty() && s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
            else if (str[i] == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.pop(); //'(' pop
            }
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}