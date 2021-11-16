#include <stdio.h>

int main()
{
    int test;
    scanf("%d", &test);

    if (test >= 90)
        printf("A");
    else if (test >= 80)
        printf("B");
    else if (test >= 70)
        printf("C");
    else if (test >= 60)
        printf("D");
    else
        printf("F");
    return 0;
}