//중요도!
//분해합, 브루트포스 알고리즘
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);

    int find = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        sum += i;

        int k = i;
        while (k != 0)
        {
            sum += k % 10;
            k /= 10;
        }

        if (sum == N)
        {
            find = i;
            break;
        }
    }
    printf("%d", find);
}