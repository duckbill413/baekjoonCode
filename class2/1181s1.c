#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Using Bubblesort
// big(n^2)의 높은 시간복잡도로 인하여 시간초과 발생

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    char **ch = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++)
    {
        ch[i] = (char *)malloc(sizeof(char) * 51);
        scanf("%s", ch[i]);
        getchar();
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (strlen(ch[j]) > strlen(ch[j + 1]))
            {
                char tmp[51];
                strcpy(tmp, ch[j]);
                strcpy(ch[j], ch[j + 1]);
                strcpy(ch[j + 1], tmp);
            }
            else if (strlen(ch[j]) == strlen(ch[j + 1]) && strcmp(ch[j], ch[j + 1]) > 0)
            {
                char tmp[51];
                strcpy(tmp, ch[j]);
                strcpy(ch[j], ch[j + 1]);
                strcpy(ch[j + 1], tmp);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i > 0 && strcmp(ch[i - 1], ch[i]) == 0)
            continue;
        printf("%s\n", ch[i]);
        free(ch[i]);
    }
    free(ch);
}

/*
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
*/