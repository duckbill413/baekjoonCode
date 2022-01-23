#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int n;
    string cloth, kind;
    while (T--)
    {
        map<string, int> map;
        cin >> n;

        while (n--)
        {
            cin >> cloth >> kind;
            if (map.find(kind) == map.end()) //해당 종류의 옷이 존재하지 않을 경우
                map.insert({kind, 1});
            else
                map[kind]++;
        }

        int ans = 1;
        for (auto i : map)
        {
            // cout << "map: " << i.second << '\n';
            ans *= (i.second + 1);
        }
        ans--;
        cout << ans << '\n';
    }
}