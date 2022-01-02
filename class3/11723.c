#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(int *BIT);
void removeBit(int *BIT);
int check(int *BIT);
void toggle(int *BIT);
void all(int *BIT);
void empty(int *BIT);

int main()
{
    int M;
    scanf("%d", &M);
    getchar();
    char order[10];
    int BIT;
    while (M--)
    {
        scanf("%s", order);
        getchar();
        if (!strcmp(order, "add"))
            add(&BIT);
        else if (!strcmp(order, "remove"))
            removeBit(&BIT);
        else if (!strcmp(order, "check"))
            printf("%d\n", check(&BIT));
        else if (!strcmp(order, "toggle"))
            toggle(&BIT);
        else if (!strcmp(order, "all"))
            all(&BIT);
        else if (!strcmp(order, "empty"))
            empty(&BIT);
    }
}
void add(int *BIT)
{
    int tmp;
    scanf("%d", &tmp);
    getchar();
    *BIT |= (1 << tmp);
}
void removeBit(int *BIT)
{
    int tmp;
    scanf("%d", &tmp);
    getchar();
    *BIT &= ~(1 << tmp);
}
int check(int *BIT)
{
    int tmp;
    scanf("%d", &tmp);
    getchar();
    if (*BIT & (1 << tmp))
        return 1;
    else
        return 0;
}
void toggle(int *BIT)
{
    int tmp;
    scanf("%d", &tmp);
    getchar();
    *BIT ^= (1 << tmp);
}
void all(int *BIT)
{
    *BIT = (1 << 21) - 1;
}
void empty(int *BIT)
{
    *BIT = 0;
}