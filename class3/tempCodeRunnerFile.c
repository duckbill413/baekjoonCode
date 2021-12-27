#include <stdio.h>
#define MAX 1000001

int min(int a, int b)
{
    return a > b ? b : a;
}
int time(int fi)
{
    if (fi == 1)
        return 0;
    if (fi % 3 == 0)
        return min(time(fi / 3) + 1, time((fi - 1) / 2) + 2);
    if (fi % 2 == 0)
        return min(time(fi / 2) + 1, time(fi - 1) + 1);
    return 1 + time(fi - 1);
}
int main()
{
    int N;
    scanf("%d", &N);

    printf("%d", time(N));
}