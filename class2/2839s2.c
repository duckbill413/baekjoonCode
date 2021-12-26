//중요도!!!!
//그리디 알고리즘 (Greedy Algorithm)
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int bag = 0;
    while (N >= 0)
    {
        if (N % 5 == 0)
        {
            bag += N / 5;
            printf("%d", bag);
            return 0;
        }
        N -= 3;
        bag++;
    }
    printf("-1");
}