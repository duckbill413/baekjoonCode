//�߿䵵!!!!!
// counting sort
//�ð������� 5�ʷ� �˳��ϳ� �޸𸮰� 8MB �����ε��� ���� �Է°����� �ſ� ũ��.
//��������� �ڿ����� �Է� ������ �ſ� ����.
#include <stdio.h>
#define MAX_VAL 10001

int main()
{
    int N;
    scanf("%d", &N);

    int cnt[MAX_VAL] = {0};
    for (int i = 0; i < N; i++)
    {
        int idx;
        scanf("%d", &idx);
        cnt[idx]++;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (cnt[i] == 0)
            continue;

        for (int j = 0; j < cnt[i]; j++)
            printf("%d\n", i);
    }
}
