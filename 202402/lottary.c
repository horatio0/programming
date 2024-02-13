#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num[6];
    srand(time(NULL));
    int i,j;
    for(i=0;i<6;i++){
        num[i]=rand()%46+1;
        for(j=0;j<i;j++) if(num[i]==num[j]) i--;
    }
    for(i=0;i<6;i++) printf("%d\t", num[i]);
    return 0;
}