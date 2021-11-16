#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ra = 0, rb = 0;
    while (a != 0)
    {
        ra = ra * 10 + a % 10;
        a /= 10;
    }
    while (b != 0)
    {
        rb = rb * 10 + b % 10;
        b /= 10;
    }
    if (ra > rb)
        printf("%d", ra);
    else
        printf("%d", rb);
}