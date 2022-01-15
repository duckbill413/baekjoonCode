//중요도!!!
//분할정복, 재귀
#include <stdio.h>
#include <stdlib.h>

int cntm1 = 0, cnt0 = 0, cnt1 = 0;

void mapCount(int **map, int r, int h, int size)
{
    int pivot = map[r][h];
    int flag = 0;
    for (int i = r; i < r + size; i++)
    {
        for (int j = h; j < h + size; j++)
        {
            if (pivot != map[i][j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
    {
        int resize = size / 3;
        mapCount(map, r, h, resize);
        mapCount(map, r + resize, h, resize);
        mapCount(map, r + resize * 2, h, resize);

        mapCount(map, r, h + resize, resize);
        mapCount(map, r + resize, h + resize, resize);
        mapCount(map, r + resize * 2, h + resize, resize);

        mapCount(map, r, h + resize * 2, resize);
        mapCount(map, r + resize, h + resize * 2, resize);
        mapCount(map, r + resize * 2, h + resize * 2, resize);
    }
    else
    {
        if (pivot == -1)
            cntm1++;
        else if (pivot == 0)
            cnt0++;
        else if (pivot == 1)
            cnt1++;
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    int **map = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
        map[i] = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);

    mapCount(map, 0, 0, N);
    printf("%d\n%d\n%d", cntm1, cnt0, cnt1);

    for (int i = 0; i < N; i++)
        free(map[i]);
    free(map);
    return 0;
}