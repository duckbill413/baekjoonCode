#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int a, b;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }
}