//중요도!
//브루트포스 알고리즘
#include <stdio.h>
#include <stdlib.h>

typedef struct _bigPeople
{
    int weight;
    int height;
} People;

void input(People *pe, int N);

int main()
{
    int N;
    scanf("%d", &N);
    People *pe = (People *)malloc(sizeof(People) * N);
    int *rank = (int *)calloc(N, sizeof(int));

    input(pe, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            int flag = 0;
            if (pe[i].weight < pe[j].weight)
                flag++;
            if (pe[i].height < pe[j].height)
                flag++;
            if (flag == 2)
                rank[i]++;
        }
        rank[i]++;
    }

    for (int i = 0; i < N; i++)
        printf("%d ", rank[i]);

    free(pe);
    free(rank);
}

void input(People *pe, int N)
{
    for (People *p = pe; p < pe + N; p++)
        scanf("%d %d", &p->weight, &p->height);
}