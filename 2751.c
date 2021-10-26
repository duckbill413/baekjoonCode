#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}
int main()
{
    int cnt;
    scanf("%d", &cnt);
    int num[1000000];
    for (int *pn = num; pn < num + cnt; pn++)
        scanf("%d", pn);

    qsort(num, cnt, sizeof(int), compare);

    for (int *pn = num; pn < num + cnt; pn++)
        printf("%d\n", *pn);
    return 0;
}

/*
int compare(const void *a, const void *b)    // �������� �� �Լ� ����
{
    int num1 = *(int *)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
    int num2 = *(int *)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

    if (num1 < num2)    // a�� b���� ���� ����
        return -1;      // -1 ��ȯ

    if (num1 > num2)    // a�� b���� Ŭ ����
        return 1;       // 1 ��ȯ

    return 0;    // a�� b�� ���� ���� 0 ��ȯ
}
*/