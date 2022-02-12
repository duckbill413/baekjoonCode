// 9251 LCS
#include <iostream>
#include <vector>
#include <string>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> table(str1.length() + 1, vector<int>(str2.length() + 1, 0));

    for (int i = 1; i <= str1.length(); i++)
    {
        for (int j = 1; j <= str2.length(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = MAX(table[i - 1][j], table[i][j - 1]);
        }
    }

    cout << table[str1.length()][str2.length()];
    return 0;
}