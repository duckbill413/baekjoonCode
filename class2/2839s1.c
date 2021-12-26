//중요도!!!
//다이나믹 프로그래밍(Dynamic programming)
#include <stdio.h>

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int main()
{
    int bag[5001] = {0};
    int N;
    scanf("%d", &N);

    bag[3] = bag[5] = 1;
    for (int i = 6; i <= N; i++)
    {
        if (bag[i - 3])
            bag[i] = bag[i - 3] + 1;
        if (bag[i - 5])
            bag[i] = bag[i] ? min(bag[i], bag[i - 5] + 1) : bag[i - 5] + 1;
    }
    bag[N] == 0 ? printf("-1") : printf("%d", bag[N]);
}