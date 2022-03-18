// 정수를 받아 그 수가 짝수이면 0, 홀수이면 1을 반환하는 함수 작성하기

#include <stdio.h>

int fun(int a);

int main(){
    int a;
    scanf("%d", &a);
    printf("%d", fun(a));
}

int fun(int a){
    if (a%2==0) return 0;
    if (a%2==1) return 1;
}