//중요도!!
//재귀함수
#include <stdio.h>
int getData(int a, int b);
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", getData(a, b));
    }
}
int getData(int a, int b)
{
    if (a == 0)
        return b;
    else if (b == 1)
        return 1;
    else
        return getData(a - 1, b) + getData(a, b - 1);
}