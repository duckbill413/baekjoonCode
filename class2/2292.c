//Áß¿äµµ!
//¼öÇÐ ±Í³³¹ý
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int cnt = 0;
    for (int sum = 2; sum <= N; cnt++)
        sum += 6 * cnt;
    if (N == 1)
        cnt = 1;
    printf("%d", cnt);
}