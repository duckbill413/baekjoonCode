#include <stdio.h>
#include <math.h>

int main()
{
    int x1, y1, r1, x2, y2, r2;
    int cnt;
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        double range = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        double drange;
        if (r1 > r2)
            drange = r1 - r2;
        else
            drange = r2 - r1;

        int result;
        if (range == 0 && r1 == r2)
            result = -1;
        else if (range < r1 + r2 && drange < range)
            result = 2;
        else if (range == r1 + r2 || drange == range)
            result = 1;
        else
            result = 0;
        printf("%d\n", result);
    }
    return 0;
}