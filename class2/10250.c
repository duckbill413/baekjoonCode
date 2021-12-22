//�߿䵵!
#include <stdio.h>

int main()
{
    int CNT;
    scanf("%d", &CNT);
    while (CNT--)
    {
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);
        int floor = N % H == 0 ? H : N % H;
        int room = (N - 1) / H + 1;
        printf("%d\n", 100 * floor + room);
    }
}