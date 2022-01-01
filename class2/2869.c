//???!
#include <stdio.h>

int main()
{
    long long day = 0;
    long long A, B, V;
    scanf("%lld %lld %lld", &A, &B, &V);

    long long lag = A - B;
    day = (V - A) / lag;
    V -= (lag * day);
    if (V <= A)
        day += 1;
    else
        day += 2;
    printf("%d", day);
}