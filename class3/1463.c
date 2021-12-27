#include <stdio.h>
#define MAX 1000001
#define min(a, b) a > b ? b : a

int num[MAX] = {0}; // vscode의 버퍼 문제
void setNum(int num[], int N);

int main()
{
    // int num[MAX] = {0};
    int N;
    scanf("%d", &N);
    setNum(num, N);
    printf("%d", num[N]);
}
void setNum(int num[], int N)
{
    for (int i = 2; i <= N; i++)
    {
        num[i] = num[i - 1] + 1;
        if (i % 2 == 0)
            num[i] = min(num[i], num[i / 2] + 1);
        if (i % 3 == 0)
            num[i] = min(num[i], num[i / 3] + 1);
    }
}