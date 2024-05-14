#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct save{
    char name[7];
    char num[14];
} Element;
#include "queue.h"

int main(){
    int count;
    Element a;
    init_queue();
    printf("연락처의 수 : ");
    scanf("%d", &count);
    for (int i = 0 ; i<count ; i++){
        printf("[%d] 이름과 연락처를 입력하시오 : ", i+1);
        scanf("%s", &a.name);
        scanf("%s", &a.num);
        enqueue(a);
    }
    printf("-----------------------------------\n-----------------------------------\n\t이름    휴대폰 번호\n-----------------------------------\n");
    for(int i = 0 ; i<count ; i++){
        a=dequeue();
        printf("[%d]     %s   %s\n", i+1, a.name, a.num);
    }
    return 0;
}