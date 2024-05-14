#include <stdio.h>
#include <string.h>
#define MAX 100
char **food;
void roop(int floor, char *preview){
    if(!(floor>=15)){
        char *a=food[0][floor];
        if(preview==NULL){
            for(int i=0;*food[i][floor]!=NULL;i++) if(strcmp(a,food[i][floor])>0) a=food[i][floor];
            roop(floor+1, a);
            printf("%s", a);
        } else {
            for(int i=0;food[i][floor-1]!=NULL;i++){
                if(food[i][floor-1]==preview){
                    for(int i=0;food[i][floor]!=NULL;i++) if(strcmp(a,food[i][floor])>0) a=food[i][floor];
                    roop(floor+1, a);
                    for(int i=0;i<floor;i++) printf("--");
                    printf("%s", a);
                }
            }
        }
    }
}
int main(void){
    int count,i,j,deep;
    scanf("%d", &count);
    **food = (int**)malloc
    for(i=0;i<count;i++){
        scanf("%d", &deep);
        for(j=0;j<deep;j++) scanf("%s", &food[i][j]);
    }
    roop(0,NULL);
}