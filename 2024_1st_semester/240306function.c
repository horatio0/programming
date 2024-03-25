#include <stdio.h>
//24/03/06 c언어 자료구조 수업
int sum(int a, int b);

int main(){
    int result, a, b;
    scanf("%d %d", &a, &b);
    result = sum(a,b);
    printf("%d", result);
}

int sum(int a, int b){
    int c;
    c = a+b;
    return c;
}