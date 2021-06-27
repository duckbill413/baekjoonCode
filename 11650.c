#include <stdio.h>
//좌표 정렬하기
void swap(int *, int *);

int main()
{
    int n;
    scanf("%d", &n);

    int num[100000][2] = {0};

    for (int i = 0; i < n; i++)
        scanf("%d %d", &num[i][0], &num[i][1]);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (num[j][0] > num[j + 1][0])
            {
                swap(&num[j][0], &num[j + 1][0]);
                swap(&num[j][1], &num[j + 1][1]);
            }
            else if (num[j][0] == num[j + 1][0])
            {
                if (num[j][1] > num[j + 1][1])
                {
                    swap(&num[j][0], &num[j + 1][0]);
                    swap(&num[j][1], &num[j + 1][1]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d %d\n", num[i][0], num[i][1]);

    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}