#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, a, b, c;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> a;
        cin >> b;
        c = a + b;
        cout << c << '\n';
    }
}