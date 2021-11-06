#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)
int rhythm(int, int);
int compareY(const void *a, const void *b);
int compareR(const void *a, const void *b);
int main()
{
    int birth;
    scanf("%d", &birth);
    int n;
    scanf("%d", &n);

    int **date = (int **)malloc(sizeof(int *) * n);

    for (int **p = date; p < date + n; p++)
    {
        *p = (int *)malloc(sizeof(int) * 2);
        scanf("%d", *p);
        *(*p + 1) = rhythm(birth, **p);
        // printf("%d %d\n", **p, *(*p+1));
    }

    for (int **p = date; p < date + n; p++)
    {
        for (int **q = p + 1; q < date + n; q++)
        {
            if (*(*p + 1) < *(*q + 1))
            {
                int *tmp = *p;
                *p = *q;
                *q = tmp;
            }
            else if (*(*p + 1) == *(*q + 1) && **p > **q)
            {
                int *tmp = *p;
                *p = *q;
                *q = tmp;
            }
        }
    }

    int **p = date;
    printf("%d", **p);

    for (int i = 0; i < n; i++)
        free(date[i]);
    free(date);
    return 0;
}

int rhythm(int birth, int date)
{
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    for (int i = 0; i < 2; i++)
    {
        sum3 += pow(birth % 10 - date % 10, 2);
        birth /= 10;
        date /= 10;
    }

    for (int i = 0; i < 2; i++)
    {
        sum2 += pow(birth % 10 - date % 10, 2);
        birth /= 10;
        date /= 10;
    }
    for (int i = 0; i < 4; i++)
    {
        sum1 += pow(birth % 10 - date % 10, 2);
        birth /= 10;
        date /= 10;
    }
    return sum1 * sum2 * sum3;
}

/*
20000101
3
20211030
20211031
20131114
*/