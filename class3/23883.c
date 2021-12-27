#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000001
#define TRUE 1
#define FALSE 0
int button[10];

int Search(int fi);
int possible(int fi);
int min(int a, int b);
int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int j;
        scanf("%d", &j);
        button[j] = 1;
    }
    printf("%d", Search(N));
}
int min(int a, int b)
{
    return a > b ? b : a;
}
int possible(int fi)
{
    if (fi == 0)
    {
        if (button[0])
            return FALSE;
        else
            return TRUE;
    }
    while (fi)
    {
        if (button[fi % 10] == 1)
            return FALSE;
        fi /= 10;
    }
    return TRUE;
}
int Search(int fi)
{
    int init = abs(fi - 100);

    int Min = MAX;
    char chtmp[10];
    for (int i = 0; i <= MAX; i++)
    {
        if (possible(i))
        {
            sprintf(chtmp, "%d", i);
            int cnt = strlen(chtmp);
            cnt += abs(i - fi);
            Min = min(Min, cnt);
        }
    }
    return min(Min, init);
}