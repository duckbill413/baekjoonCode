#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int N, M;
    long long B;
    scanf("%d %d %lld", &N, &M, &B);

    int **block = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++)
        block[i] = (int *)calloc(M, sizeof(int));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &block[i][j]);

    int Time = INT_MAX, height;
    // 0�� ~ 256��
    for (int k = 0; k <= 256; k++)
    {
        int time = 0, tmp = B;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (block[i][j] < k) // block �ֱ� +1��
                {                    //���غ��� ���� ���
                    time += k - block[i][j];
                    tmp -= k - block[i][j];
                }
                else if (block[i][j] > k) // block ���� �κ��丮�� �ֱ� +2��
                {                         //���غ��� ���� ���
                    time += (block[i][j] - k) * 2;
                    tmp += (block[i][j] - k);
                }
            }
        }
        if (tmp >= 0) //�κ��丮 ���� ���� ������ �ƴ� ���
        {
            if (time <= Time) //���̰� ���� ���� �켱�̹Ƿ� '=' ����
            {
                Time = time;
                height = k;
            }
        }
    }
    printf("%d %d", Time, height);
    for (int i = 0; i < N; i++)
        free(block[i]);
    free(block);
}