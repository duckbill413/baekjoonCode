#include <stdio.h>
#define cnt 1000

int main()
{
    int N;
    scanf("%d", &N);

    int num[cnt];
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    int max = 0;
    double result = 0;
    for (int i = 0; i < N; i++)
    {
        if (max < num[i])
            max = num[i];
        result += num[i];
    }

    printf("%.2lf", (result / max * 100) / N);
    return 0;
}