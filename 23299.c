#include <stdio.h>

typedef struct
{
    int start, end;
    int p[6];
} User;

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);
    int q[6];
    for (int i = 0; i < 6; i++)
        scanf("%d", &q[i]);

    User us[500];
    for (User *p = us; p < us + n; p++)
    {
        scanf("%d %d", &p->start, &p->end);
        for (int i = 0; i < 6; i++)
        {
            scanf("%d", &p->p[i]);
        }
    }

    int start = us[0].start;
    int end = us[0].end;

    int total = 0;
    for (int i = start; i <= end; i++)
    {
    }
}