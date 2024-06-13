#include <stdio.h>

int main(void){
    int a;
    char b[1001];
    scanf("%s", &b);
    rewind(stdin);
    scanf(" %d", &a);
    printf("%s", b[a-1]);
}