// 17219 비밀번호 찾기
// vector sort(compare), binary search
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef struct _info
{
    string id;
    string pw;
} Info;
bool compare(Info a, Info b)
{
    if (a.id.compare(b.id) < 0)
        return true;
    else
        return false;
}
int binSearch(string target, vector<Info> &site, int start, int end);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    Info tmp;
    cin >> N >> M;
    cin.ignore();
    vector<Info> site;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp.id >> tmp.pw;
        cin.ignore();
        site.push_back(tmp);
    }

    sort(site.begin(), site.end(), compare);
    string find;
    while (M--)
    {
        cin >> find;
        Info re = site[binSearch(find, site, 0, N - 1)];
        cout << re.pw << '\n';
    }
}
int binSearch(string target, vector<Info> &site, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;
    int comp = target.compare(site[mid].id);
    if (comp == 0)
        return mid;
    else if (comp > 0)
        return binSearch(target, site, mid + 1, end);
    else
        return binSearch(target, site, 0, mid - 1);
}