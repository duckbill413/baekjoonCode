//중요도!!
//분할정복, 재귀
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
void Divide(char *str, char **map, int r, int h, int size);
int Unity(char **map, int r, int h, int size, char *p);
void append(char *str, char ch);
int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    char str[30000];

    char **map = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++)
        map[i] = (char *)malloc(sizeof(char *) * N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", map[i]);
        getchar();
    }

    Divide(str, map, 0, 0, N);

    printf("%s", str);

    for (int i = 0; i < N; i++)
        free(map[i]);
    free(map);
    return 0;
}
void Divide(char *str, char **map, int r, int h, int size)
{
    char pivot;
    if (Unity(map, r, h, size, &pivot))
        append(str, pivot);
    else
    {
        int resize = size / 2;
        append(str, '(');
        Divide(str, map, r, h, resize);
        Divide(str, map, r, h + resize, resize);
        Divide(str, map, r + resize, h, resize);
        Divide(str, map, r + resize, h + resize, resize);
        append(str, ')');
    }
}
int Unity(char **map, int r, int h, int size, char *p)
{
    char pivot = map[r][h];
    *p = pivot;
    for (int i = r; i < r + size; i++)
    {
        for (int j = h; j < h + size; j++)
        {
            if (pivot != map[i][j])
                return FALSE;
        }
    }
    return TRUE;
}
void append(char *str, char ch)
{
    char *p = str;
    while (*p != '\0')
        p++;
    *p = ch;
    *(p + 1) = 0;
}