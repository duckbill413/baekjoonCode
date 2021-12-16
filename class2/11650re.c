#include <stdio.h>
#include <stdlib.h>
// qsort �������� Ȱ��
typedef struct point
{
    int x, y;
} Point;

int compareX(const void *a, const void *b) // �������� �� �Լ� ����
{
    Point *num1 = (Point *)a;
    Point *num2 = (Point *)b;

    if (num1->x < num2->x) // a�� b���� ���� ����
        return -1;         // -1 ��ȯ

    if (num1->x > num2->x) // a�� b���� Ŭ ����
        return 1;          // 1 ��ȯ

    return 0; // a�� b�� ���� ���� 0 ��ȯ
}

int compareY(const void *a, const void *b) // �������� �� �Լ� ����
{
    Point *num1 = (Point *)a;
    Point *num2 = (Point *)b;

    if (num1->y < num2->y) // a�� b���� ���� ����
        return -1;         // -1 ��ȯ

    if (num1->y > num2->y) // a�� b���� Ŭ ����
        return 1;          // 1 ��ȯ

    return 0; // a�� b�� ���� ���� 0 ��ȯ
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