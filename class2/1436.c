#include <stdio.h>

int main()
{
    int start = 666;
    int N;
    scanf("%d", &N);
    int cnt = 0;
    int cnt_6 = 0;
    while (1)
    {
        int k = start;
        cnt_6 = 0;
        while (k != 0)
        {
            if (k % 10 == 6)
                cnt_6++;
            else
                cnt_6 = 0;
            if (cnt_6 == 3)
            {
                cnt++;
                break;
            }
            k /= 10;
        }

        if (cnt == N)
        {
            printf("%d", start);
            break;
        }
        start++;
    }
}