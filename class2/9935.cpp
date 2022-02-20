// 9935 문자열 폭발
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    string bomb;
    cin >> str >> bomb;

    string ans = "";

    int bombLen = bomb.length();

    for (int i = 0; i < str.length(); i++)
    {
        ans += str[i];

        if (ans[ans.length() - 1] == bomb[bombLen - 1])
        {
            bool flag = true;
            for (int j = 2; j <= bombLen; j++)
            {
                if (ans[ans.length() - j] != bomb[bombLen - j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                ans.erase(ans.end() - bomb.length(), ans.end());
        }
    }

    if (ans.length() == 0)
        cout << "FRULA";
    else
        cout << ans;
    return 0;
}