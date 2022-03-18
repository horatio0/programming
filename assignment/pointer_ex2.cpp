/* 10*10 이하의 정수형 이차원 배열을 입력받아
그 배열의 각 행의 요소의 합을 출력하는 프로그램을 작성하시오.

[입력]
3 4
1 2 3 4
5 6 7 8
9 10 11 12

[출력]
10
26
42
*/


#include <stdio.h>
#include <stdlib.h>

int main(){
    int **ptr = NULL;
    int x[2], re=0;
    for (int a=0;a<=1;a++) scanf("%d",&x[a]);
    ptr = (int **)malloc(sizeof(int *)*x[0]);
    for (int a=0;a<x[0];a++) ptr[a] = (int *)malloc(sizeof(int)*x[1]);
    for(int i=0;i<x[0];i++){
        for(int j=0;j<x[1];j++) scanf("%d", &ptr[i][j]);
    }
    for(int i=0;i<x[0];i++){
        for(int j=0;j<x[1];j++) re+=ptr[i][j];
        printf("%d\n", re);
        re=0;
    }
    for (int a=0;a<x[0];a++) free(ptr[a]);
    free(ptr);
}