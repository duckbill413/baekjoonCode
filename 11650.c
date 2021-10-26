#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct point
{
    int x, y;
} Point;

void swap(Point*, Point*);
int Partition(Point*, int, int, int);
void QuickSort(Point*, int, int, int);

int main()
{
    int n;
    scanf("%d", &n);
    Point* po = (Point*)malloc(sizeof(Point) * n);

    for (Point* p = po; p < po + n; p++)
        scanf("%d %d", &p->x, &p->y);

    QuickSort(po, 0, n - 1, 1);
    //QuickSort(po, 0, n - 1, 0);
    int left = 0;
    int right = n - 1;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        while ((po + i)->x == (po + i + 1)->x) {
            right = i + 1;
            cnt++;
            i++;
        }
        if (cnt >= 1)
        {
            left = right - cnt;
            QuickSort(po, left, right, 1);
        }
        cnt = 0;
    }

    for (Point* p = po; p < po + n; p++)
        printf("%d %d\n", p->x, p->y);

    free(po);
    return 0;
}

void swap(Point* a, Point* b)
{
    Point tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(Point* po, int left, int right, int select)
{
    if (select == 0)
    {
        int pivot = (po+left)->x;
        int low = left + 1;
        int high = right;

        while (low <= high)
        {
            while (pivot >= (po + low)->x && low <= right)
                low++;
            while (pivot <= (po + high)->x && high >= left + 1)
                high--;

            if (low <= high)
                swap(po + left, po + right);
        }
        swap(po + left, po + high);
        return high;
    }
    else if (select == 1)
    {
        int pivot = (po + left)->y;
        int low = left + 1;
        int high = right;

        while (low <= high)
        {
            while (pivot >= (po + low)->y && low <= right)
                low++;
            while (pivot <= (po + high)->y && high >= left + 1)
                high--;

            if (low <= high)
                swap(po + left, po + right);
        }
        swap(po + left, po + high);
        return high;
    }
}

void QuickSort(Point* po, int left, int right, int select)
{
    if (left <= right)
    {
        int pivot = Partition(po, left, right, select);
        QuickSort(po, left, pivot - 1, select);
        QuickSort(po, pivot + 1, right, select);
    }
}