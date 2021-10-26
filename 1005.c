#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    while (num--)
    {
        int n, k;
        int time[1000];
        int tcase[100000][2];
        int win;
        int sum = 0;

        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &time[i]);
        for (int i = 0; i < k; i++)
            scanf("%d %d", &tcase[i][0], &tcase[i][1]);
        scanf("%d", &win);

        for (int k = 1; k <= n; k++)
        {
            int big = 0;
            int big_time = 0;
            for (int p = 0; p < k; p++)
            {
                if (tcase[p][0] == k)
                {
                    if (time[tcase[p][1] - 1] > big_time || big_time == 0)
                    {
                        big_time = time[tcase[p][1] - 1];
                        big = tcase[p][1];
                    }
                }
            }
            sum += big_time;
            k = big;
            if (k == win)
            {
                sum += time[win - 1];
                break;
            }
        }
        printf("%d\n", sum);
    }
}
/*
1
4 4
10 1 100 10
1 2
1 3
2 4
3 4
4
*/