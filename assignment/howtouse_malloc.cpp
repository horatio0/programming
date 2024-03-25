/*100개 이하의 정수를 입력받아 
첫 줄에 짝수 번째 숫자를 출력하고
둘째 줄에 홀수 번째 숫자를 출력하는 프로그램을 만들어 보시오

[입력]
5
1 2 3 4 5

[출력]
2 4
1 3 5*/

#include <stdio.h>
#include <malloc.h>

int main(){
    int a;
    scanf("%d", &a);
    int *b = (int *)malloc(sizeof(int)*a);
    for(int c=0;c<a;c++)  scanf("%d",&b[c]);
    for(int c=1;c<a;c=c+2)  printf("%d\t", b[c]);
    printf("\n");
    for(int c=0;c<a;c=c+2)  printf("%d\t", b[c]);
    free(b);
    return 0;
}