#include <stdio.h>

int main()
{
    int sum = 0;
    int N;
    scanf("%d", &N);
    getchar();
    char tmp[101];
    scanf("%s", tmp);

    for (int i = 0; i < N; i++)
    {
        sum += (tmp[i] - '0');
    }
    printf("%d", sum);
}