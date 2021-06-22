#include <stdio.h>
//재귀함수의 표현
int fun(int);

int main()
{
    int n;
    scanf("%d", &n);
    int result = fun(n);
    printf("%d", result);
    return 0;
}

int fun(int n)//재귀함수
{
    if (n <= 1)
        return n;

    return fun(n - 1) + fun(n - 2);
}