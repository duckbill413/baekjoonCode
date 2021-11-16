#include <stdio.h>
#include <math.h>
#define cnt 6

int main()
{
    int num[cnt];
    int sum = 0;
    for (int i = 0; i < cnt - 1; i++)
    {
        scanf("%d", &num[i]);
        sum += pow(num[i], 2);
    }
    num[cnt - 1] = sum % 10;
    printf("%d", num[cnt - 1]);
    return 0;
}