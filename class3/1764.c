//중요도!!!!!
//퀵소트, 문자열 정렬, 문자열 이분탐색
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int compare(const void *left, const void *right) //배열이 원소로 들어온다
{
    // printf("cmp: %s %s\n", *(char **)left, *(char **)right);
    if (strcmp(*(char **)left, *(char **)right) > 0) //문자열을 오름차순 정렬
        return 1;
    else
        return -1;
}
int binSearch(char *fi, char **str, int start, int end); //문자열 이분 탐색
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();

    // N, M개 만큼 동적할당 하고 문자열 입력
    char **str1 = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++)
    {
        char tmp[21]; //임시 문자열을 선언하고 크기를 확인한뒤 동적할당
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

    //문자열에 대하여 오름차순으로 정렬
    qsort((void **)str1, N, sizeof(str1[0]), compare);
    qsort((void **)str2, M, sizeof(str2[0]), compare);

    int cnt = 0;                                       //듣보잡 문자열의 개수
    char **str3 = (char **)malloc(sizeof(char *) * N); // N을 이용하여 비교할 예정이므로 N개 동적할당
    for (int i = 0; i < N; i++)
    {
        if (binSearch(str1[i], str2, 0, M - 1))
        {
            str3[cnt] = (char *)malloc(sizeof(char) * (strlen(str1[i] + 1))); //듣보잡 문자열을 배열에 저장
            strcpy(str3[cnt], str1[i]);
            cnt++;
        }
    }
    //듣보잡 문자열의 개수와 문자열을 출력
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%s\n", str3[i]);

    //동적할당 하였던 문자열의 동적할당 해제
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
int binSearch(char *fi, char **str, int start, int end) //멤버변수(찾고자 하는 문자열, 찾는 배열, 시작 번지, 마지막 번지)
{
    if (start > end) //문자열을 찾지 못하였을 경우
        return FALSE;
    int mid = (start + end) / 2;
    // printf("str: %s\n", str[mid]);
    if (strcmp(fi, str[mid]) > 0) //찾고자하는 문자열이 이후에 위치
        return binSearch(fi, str, mid + 1, end);
    else if (strcmp(fi, str[mid]) < 0) //찾고자하는 문자열이 이전에 위치
        return binSearch(fi, str, start, mid - 1);
    else
        return TRUE; //문자열 찾기 성공
}