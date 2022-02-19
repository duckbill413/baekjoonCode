// 11650 좌표 정렬하기
#include <stdio.h>
#include <stdlib.h>
// qsort 내장정렬 활용
typedef struct point
{
    int x, y;
} Point;
int compare(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    if (p1->x > p2->x)
        return 1;
    else if (p1->x == p2->x && p1->y > p2->y)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    Point *point = (Point *)malloc(sizeof(Point) * n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &point[i].x, &point[i].y);

    qsort(point, n, sizeof(point[0]), compare);
    for (Point *p = point; p < point + n; p++)
        printf("%d %d\n", p->x, p->y);
    free(point);
    return 0;
}