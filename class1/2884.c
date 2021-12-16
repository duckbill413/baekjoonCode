#include <stdio.h>

int main()
{
    int hour, min;
    scanf("%d %d", &hour, &min);

    int result;
    result = hour * 60 + min - 45;
    if (result < 0)
        result += 24 * 60;

    printf("%d %d", result / 60, result % 60);
    return 0;
}