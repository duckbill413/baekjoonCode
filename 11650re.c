#include <stdio.h>
#include <stdlib.h>
// qsort 내장정렬 활용
typedef struct point
{
    int x, y;
} Point;

int compareX(const void *a, const void *b) // 오름차순 비교 함수 구현
{
    Point *num1 = (Point *)a;
    Point *num2 = (Point *)b;

    if (num1->x < num2->x) // a가 b보다 작을 때는
        return -1;         // -1 반환

    if (num1->x > num2->x) // a가 b보다 클 때는
        return 1;          // 1 반환

    return 0; // a와 b가 같을 때는 0 반환
}

int compareY(const void *a, const void *b) // 오름차순 비교 함수 구현
{
    Point *num1 = (Point *)a;
    Point *num2 = (Point *)b;

    if (num1->y < num2->y) // a가 b보다 작을 때는
        return -1;         // -1 반환

    if (num1->y > num2->y) // a가 b보다 클 때는
        return 1;          // 1 반환

    return 0; // a와 b가 같을 때는 0 반환
}

int main()
{
    int n;
    scanf("%d", &n);
    Point *po = (Point *)malloc(sizeof(Point) * n);

    for (Point *p = po; p < po + n; p++)
        scanf("%d %d", &p->x, &p->y);

    qsort(po, n, sizeof(Point), compareX);
    // qsort(po, n, sizeof(Point), compareY);
    for (Point *p = po; p < po + n; p++)
    {
        int cnt = 1;

        Point *ps = p;
        while (ps->x == (ps + 1)->x)
        {
            ps++;
            cnt++;
        }
        qsort(p, cnt, sizeof(Point), compareY);
    }

    for (Point *p = po; p < po + n; p++)
        printf("%d %d\n", p->x, p->y);

    free(po);
    return 0;
}