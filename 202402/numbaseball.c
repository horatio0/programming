//숫자야구
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j, win=0;

void setnum(int *n){
    srand(time(NULL));
    for(i=0;i<3;i++){
        n[i]=rand()%10;
        for(j=0;j<i;j++) if(n[i]==n[j]) i--;
    }
}

void stba(int *n, int *in){
    int x,y, st=0, ba=0;
    for(x=0;x<3;x++){
        for(y=0;y<3;y++){
            if(x==y){
                if(n[x]==in[y]) st++;
            } else {
                if(n[x]==in[y]) ba++;
            }
        }
    }
    printf("스트라이크 : %d / 볼 : %d\n", st, ba);
    if(st==3){
        printf("승리!\n");
        win=1;
    }
}

int main(){
    int count=0, num[3], input[3];
    int *n=num, *in=input;
    setnum(n);
    while(count<10){        
        printf("0~9 까지의 숫자 3개를 입력하시오 : ");
        for(i=0;i<3;i++) scanf("%d", &input[i]); 
        stba(n, in);
        if(win==1) break;
        count++;
    }
    return 0;
}