//중요도!!!
//사분할로 생각
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, r, c, cnt = 0;
int result;

void cntBlock(int x, int y, int n);
int main()
{
    scanf("%d %d %d", &N, &r, &c);
    cntBlock(0, 0, (int)pow(2, N));
    printf("%d", result);
}
void cntBlock(int x, int y, int n)
{
    if (r == y && c == x)
    {
        result = cnt;
        return;
    }
    if (y <= r && r < y + n && x <= c && c < x + n)
    {
        int newNum = (int)(n / 2);
        cntBlock(x, y, newNum);
        cntBlock(x + newNum, y, newNum);
        cntBlock(x, y + newNum, newNum);
        cntBlock(x + newNum, y + newNum, newNum);
    }
    else
    {
        cnt += n * n;
    }
}