#include <stdio.h>

int sum(int a, int b);

int main(){
    int result, num1, num2;
    scanf("%d %d", &num1, &num2);
    result = sum(num1,num2);
    printf("%d", result);
}

int sum(int a, int b){
    return a+b;
}