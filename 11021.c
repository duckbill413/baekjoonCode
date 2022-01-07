#include <stdio.h>

int main(){
    int N, a, b;
    scanf("%d", &N);
    int cnt = 1;
    while(N--){
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", cnt, a+b);
        cnt++;
    }
}