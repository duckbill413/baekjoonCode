// 13172 페르마의 소정리
#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007;

ll gcd(ll a, ll b) //유클리드 호제법
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
ll solution(ll a, ll b)
{
    if (b == 1)
        return a;
    if (b & 1) //홀수 일 경우
        return a * solution(a, b - 1) % MOD;
    ll res = solution(a, b / 2);
    return res * res % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll ans = 0;
    int M;
    cin >> M;
    while (M--)
    {
        ll a, b;
        cin >> a >> b;
        // a와 b는 배수 관계가 아니여야 한다.
        ll g = gcd(a, b); //배수 관계가 아니여야 하므로 최대공배수를 구하여 나누어 준다.
        a /= g;
        b /= g;
        ll inv = solution(a, MOD - 2);
        ans += b * inv % MOD;
        ans %= MOD;
    }
    cout << ans;
}