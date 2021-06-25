#include <stdio.h>
//소트인사이드
//각 자리수를 내림차순으로 정렬
int main()
{
    int num;
    scanf("%d", &num);
    int array[10] = {0};
    int sum = 0;
    int i = 0;
    while (num != 0)
    {
        array[i] = num % 10;
        num /= 10;
        i++;
    }
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = 0; k < i - j - 1; k++)
        {
            if (array[k] > array[k + 1])
            {
                int tmp = array[k + 1];
                array[k + 1] = array[k];
                array[k] = tmp;
            }
        }
    }
    int multi = 1;
    for (int j = 0; j < i; j++)
    {
        sum += multi * array[j];
        multi *= 10;
    }
    printf("%d", sum);
    return 0;
}
`