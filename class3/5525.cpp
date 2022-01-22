// 중요도!!!!
// 문자열 비교 알고리즘 KMP
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getFail(string target)
{
    int m = target.length();
    vector<int> fail(m);
    fail[0] = 0;

    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && target[i] != target[j])
            j = fail[j - 1];
        if (target[i] == target[j])
            fail[i] = ++j;
        else
            fail[i] = 0;
    }
    return fail;
}

int KMP(string pattern, string target)
{
    int n = pattern.length();
    int m = target.length();
    vector<int> fail = getFail(target);
    int CNT = 0;

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && pattern[i] != target[j])
            j = fail[j - 1];

        if (pattern[i] == target[j])
        {
            if (j == m - 1)
            {
                CNT++;
                j = fail[j];
            }
            else
                j++;
        }
    }
    return CNT;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string pattern, target;

    cin >> N >> M;
    cin.ignore();
    cin >> pattern;

    for (int i = 0; i < N; i++)
    {
        target.push_back('I');
        target.push_back('O');
    }
    target.push_back('I');

    // cout << target << endl;
    cout << KMP(pattern, target);
    return 0;
}