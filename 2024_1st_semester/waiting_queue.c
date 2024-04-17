#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct waiting{
    int id;
    int nperson;
    char info[32];
} Element;

#include "queue.h"

int main(){
    Element waiting[4] = {{12,2,"010-xxxx-1234"}, {13, 4, "010-xxxx-7809"}, {14, 3, "010-4566-9765"}, {15,2,"010-4679-1346"}};
    init_queue();
    for (int i = 0; i<4;i++){
        printf("웨이팅 신청을 완료했습니다. 대기번호 : %d번 인원 : %d명\n", waiting[i].id, waiting[i].nperson);
        enqueue(waiting[i]);
    }
    while(!is_empty()){
        Element w = dequeue();
        printf("웨이팅 번호 %d번 입장하실 차례입니다. (%d명, %s)\n", w.id, w.nperson, w.info);
    }
}