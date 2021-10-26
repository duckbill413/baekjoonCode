#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int num;
        scanf("%d", &num);
        int planx, plany, planr;
        int cnt = 0;
        for (int j = 0; j < num; j++)
        {
            scanf("%d %d %d", &planx, &plany, &planr);
            double d1 = sqrt(pow(planx - x1, 2) + pow(plany - y1, 2));
            double d2 = sqrt(pow(planx - x2, 2) + pow(plany - y2, 2));
            if (d1 < planr && d2 > planr)
                cnt++;
            else if (d1 > planr && d2 < planr)
                cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}