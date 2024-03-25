#include <Stdio.h>

void check(char c);

int main(){
        char c;
        printf("문자를 입력하시오 : ");
        scanf(" %c", &c);
        check(c);

}

void check(char c){
    if('A' <= c && 'Z' >= c) printf("대문자입니다.\n");
    else if('a'<=c && 'z'>=c) printf("소문자입니다.\n");
    else printf("%c는 알파벳이 아닙니다.\n", c);
}