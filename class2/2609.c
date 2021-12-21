//중요도!!
//유클리드 호제법 - 최대, 최솟값 찾기
#include <stdio.h>

int gcd(int a, int b)
{
    while (b > 0)
    {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}
int lcm(int a, int b)
{
    int g = gcd(a, b);
    return a * b / g;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    printf("%d", lcm(a, b));
}