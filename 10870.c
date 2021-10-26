#include <stdio.h>

int fun(int);

int main()
{
    int n;
    scanf("%d", &n);
    int result = fun(n);
    printf("%d", result);
    return 0;
}

int fun(int n)
{
    if (n <= 1)
        return n;

    return fun(n - 1) + fun(n - 2);
}