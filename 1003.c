#include <stdio.h>

void fibonacci(int, int *, int *);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        int cnt0 = 0, cnt1 = 0;

        fibonacci(num, &cnt0, &cnt1);
        printf("%d %d\n", cnt0, cnt1);
    }
    return 0;
}
void fibonacci(int n, int *cnt0, int *cnt1)
{
    int fi0 = 0, fi1 = 1, fi2 = 0;
    for (int i = 0; i <= n; i++)
    {
        fi0 = fi1;
        fi1 = fi2;
        fi2 = fi0 + fi1;
    }
    *cnt0 = fi0;
    *cnt1 = fi1;
}