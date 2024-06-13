#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack{
    char *name;
    int count;
    int f;
    stack **upper;
    stack **under;
} stack;
stack **food, *last_address;
int num=0;

void first(int count){
    food=(stack**)malloc(sizeof(stack*)*count);
}

void push(char *name, int deep, int count, int i){
    stack *p;
    p->name = name;
    p->count = 0;
    p->f = deep+1;
    p->upper = last_address;
    p->under = (stack*)malloc(sizeof(stack)*count);
    last_address->under[last_address->count]=p;
    last_address=p;
}

void setting_address(char *name, int count, int a, int isfirst){
    if (isfirst==1){
        for(int i=0;i<count;i++){
            if(strcmp(food[i]->name,name)==0){
                last_address = food[i];
                food[i]->count++;
            }
            else last_address = food[a];
        }
    }else{
        for(int i=0;last_address->under[i]!=NULL;i++) if(strcmp(last_address->under[i]->name,name)==0) last_address->count++;
    }
}

int main(void){
    int deep, count,isfirst;
    char name[16];
    scanf("%d", &count);
    first(count);
    for(int i=0;i<count;i++){
        isfirst=1;
        scanf("%d", &deep);
        for(int j=0;j<deep;j++){
            scanf("%d", &name);
            setting_address(name,count,i,isfirst);
            push(name, j, count,i);
            isfirst=0;
        }
    }
    char **imsi = (char*)malloc(sizeof(char*)*count);
    last_address = food[0];
    for(int i=0;i<count;i++){

    }
}