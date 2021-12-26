//Áß¿äµµ!!!
//ÇØ½Ì

#include <stdio.h>
#define M 1234567891
int main()
{
    int L;
    scanf("%d", &L);
    getchar();
    char str[51];
    scanf("%s", str);

    long long sum = 0;
    long long tmp = 1;

    for (int i = 0; i < L; i++)
    {
        sum = (sum + (str[i] - 'a' + 1) * tmp) % M;
        tmp = (tmp * 31) % M;
    }

    printf("%lld\n", sum);
}