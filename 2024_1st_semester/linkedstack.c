#include <stdio.h>
#include <stdlib.h>
typedef int Element;
#include "linkedstack.h"

int main(void){
    int A[7] = {0,1,1,2,3,4,8};
    init_stack();
    printf("스택 테스트\n입력 데이터 : ");
    for(int i=0;i<7;i++){
        printf("%3d", A[i]);
        push(A[i]);
    }
    printf("\n출력 데이터 : ");
    while(!is_empty()) printf("%3d", pop());
    printf("\n");
    destroy_stack();
}