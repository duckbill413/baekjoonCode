#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);

        printf("Pairs for %d: ", num);

        int found = 0;
        for (int p = 1; p <= 12; p++)
        {
            for (int q = p + 1; q <= 12; q++)
            {
                if (p + q == num)
                {
                    if (found)
                        printf(", ");
                    printf("%d %d", p, q);
                    found++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}