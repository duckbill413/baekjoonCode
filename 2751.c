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
int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환

    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환

    return 0;    // a와 b가 같을 때는 0 반환
}
*/