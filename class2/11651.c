//�߿䵵!!!!
// quicksort
#include <stdio.h>
#include <stdlib.h>

typedef struct _point
{
    int x, y;
} Point;
int compare(const void *left, const void *right);
int main()
{
    int N;
    scanf("%d", &N);
    Point *p = (Point *)malloc(sizeof(Point) * N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &p[i].x, &p[i].y);

    qsort(p, N, sizeof(Point), compare);

    for (int i = 0; i < N; i++)
        printf("%d %d\n", p[i].x, p[i].y);
    free(p);
}
int compare(const void *left, const void *right)
{
    Point *a = (Point *)left;
    Point *b = (Point *)right;
    if (a->y > b->y)
        return 1;
    else if (a->y < b->y)
        return -1;
    else if (a->x > b->x)
        return 1;
    else
        return -1;
}