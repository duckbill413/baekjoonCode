//�߿䵵!
//���Ʈ���� �˰���
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int *card = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &card[i]);

    int close;
    int closeSum;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int sum = card[i] + card[j] + card[k];
                //����: M�� ���� ����, M�� ���� �ʴ°�
                if ((M - sum) < close && M - sum >= 0 || (i == 0 && j == 1 && k == 2))
                {
                    close = abs(sum - M);
                    closeSum = sum;
                }
            }
        }
    }

    printf("%d", closeSum);
    free(card);
}