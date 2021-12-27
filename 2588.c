#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    int sum = 0;
    int R = 1;
    while (B != 0)
    {
        int tmp = A * (B % 10);
        printf("%d\n", tmp);
        B /= 10;
        sum += tmp * R;
        R *= 10;
    }
    printf("%d", sum);
}