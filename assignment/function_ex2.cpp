// 문자열을 매개변수로 받아 공백을 제거하여 출력하는 함수 만들기

#include <stdio.h>


void print(char* a);

int main() {
    char a[50];
    fgets(a, 50, stdin);
    print(a);
}

void print(char* a) {
    for (int b = 0; b < 50; b++) {
        if(a[b] != ' ') printf("%c", a[b]);
        if(a[b+1] == '\n') break;
    }
}