#include <stdio.h>

int main()
{
    int year;
    scanf("%d", &year);

    int result = 0;
    if (year % 400 == 0)
        result = 1;
    else if (year % 100 == 0)
        result = 0;
    else if (year % 4 == 0)
        result = 1;
    printf("%d", result);
    return 0;
}