//가위바위보
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int a, b, wincount=0, count=0;
    float winrate;
    while(1){
        printf("-1 : 종료 / 0 : 가위 / 1 : 바위 / 2 : 보\n입력 : ");
        srand(time(NULL));
        b=rand()%3; 
        scanf("%d", &a);
        if(a==-1){
            winrate = (float)wincount/count;
            printf("승률 : %f", winrate);
            break;
        }
        switch(a){
            case 0:
                count++;
                if(b==0) printf("비겼습니다\tc:%d w:%d\n", count, wincount);
                else if(b==1) printf("졌습니다\tc:%d w:%d\n", count, wincount);
                else if(b==2){
                    wincount++;
                    printf("이겼습니다\tc:%d w:%d\n", count, wincount);
                }
                break;
            case 1:
                count++;
                if(b==0){
                    wincount++;
                    printf("이겼습니다\tc:%d w:%d\n", count, wincount);
                }
                else if(b==1) printf("비겼습니다\tc:%d w:%d\n", count, wincount);
                else if(b==2) printf("졌습니다\tc:%d w:%d\n", count, wincount);
                break;
            case 2:
                count++;
                if(b==0) printf("졌습니다\tc:%d w:%d\n", count, wincount);
                else if(b==1){
                    wincount++;
                    printf("이겼습니다\tc:%d w:%d\n", count, wincount);
                }
                else if(b==2) printf("비겼습니다\tc:%d w:%d\n", count, wincount);
                break;
        }
    }
}