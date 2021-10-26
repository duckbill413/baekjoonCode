#include <stdio.h>

int fibonacci(int, int *, int *);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        int cnt0 = 0, cnt1 = 0;

        int result = fibonacci(num, &cnt0, &cnt1);
        printf("%d %d\n", cnt0, cnt1);
    }
    return 0;
}
int fibonacci(int n, int *cnt0, int *cnt1)
{
    if (n == 0)
    {
        (*cnt0)++;
        return 0;
    }
    else if (n == 1)
    {
        (*cnt1)++;
        return 1;
    }
    else
    {
        return fibonacci(n - 1, cnt0, cnt1) + fibonacci(n - 2, cnt0, cnt1);
    }
}