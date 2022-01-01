//�߿䵵!!!!!
//����Ʈ, ���ڿ� ����, ���ڿ� �̺�Ž��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int compare(const void *left, const void *right) //�迭�� ���ҷ� ���´�
{
    // printf("cmp: %s %s\n", *(char **)left, *(char **)right);
    if (strcmp(*(char **)left, *(char **)right) > 0) //���ڿ��� �������� ����
        return 1;
    else
        return -1;
}
int binSearch(char *fi, char **str, int start, int end); //���ڿ� �̺� Ž��
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();

    // N, M�� ��ŭ �����Ҵ� �ϰ� ���ڿ� �Է�
    char **str1 = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++)
    {
        char tmp[21]; //�ӽ� ���ڿ��� �����ϰ� ũ�⸦ Ȯ���ѵ� �����Ҵ�
        scanf("%s", tmp);
        getchar();
        str1[i] = (char *)malloc(sizeof(char) * (strlen(tmp + 1)));
        strcpy(str1[i], tmp);
    }
    char **str2 = (char **)malloc(sizeof(char *) * M);
    for (int i = 0; i < M; i++)
    {
        char tmp[21];
        scanf("%s", tmp);
        getchar();
        str2[i] = (char *)malloc(sizeof(char) * (strlen(tmp + 1)));
        strcpy(str2[i], tmp);
    }

    //���ڿ��� ���Ͽ� ������������ ����
    qsort((void **)str1, N, sizeof(str1[0]), compare);
    qsort((void **)str2, M, sizeof(str2[0]), compare);

    int cnt = 0;                                       //�躸�� ���ڿ��� ����
    char **str3 = (char **)malloc(sizeof(char *) * N); // N�� �̿��Ͽ� ���� �����̹Ƿ� N�� �����Ҵ�
    for (int i = 0; i < N; i++)
    {
        if (binSearch(str1[i], str2, 0, M - 1))
        {
            str3[cnt] = (char *)malloc(sizeof(char) * (strlen(str1[i] + 1))); //�躸�� ���ڿ��� �迭�� ����
            strcpy(str3[cnt], str1[i]);
            cnt++;
        }
    }
    //�躸�� ���ڿ��� ������ ���ڿ��� ���
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%s\n", str3[i]);

    //�����Ҵ� �Ͽ��� ���ڿ��� �����Ҵ� ����
    for (int i = 0; i < N; i++)
        free(str1[i]);
    for (int i = 0; i < M; i++)
        free(str2[i]);
    for (int i = 0; i < cnt; i++)
        free(str3[i]);
    free(str1);
    free(str2);
    free(str3);
}
int binSearch(char *fi, char **str, int start, int end) //�������(ã���� �ϴ� ���ڿ�, ã�� �迭, ���� ����, ������ ����)
{
    if (start > end) //���ڿ��� ã�� ���Ͽ��� ���
        return FALSE;
    int mid = (start + end) / 2;
    // printf("str: %s\n", str[mid]);
    if (strcmp(fi, str[mid]) > 0) //ã�����ϴ� ���ڿ��� ���Ŀ� ��ġ
        return binSearch(fi, str, mid + 1, end);
    else if (strcmp(fi, str[mid]) < 0) //ã�����ϴ� ���ڿ��� ������ ��ġ
        return binSearch(fi, str, start, mid - 1);
    else
        return TRUE; //���ڿ� ã�� ����
}