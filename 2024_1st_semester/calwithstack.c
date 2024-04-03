#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_Size 100
typedef char EforC;
typedef double EforD;
#include "ArrayStack.h"
char result[Max_Size]="";

int precedence(char op){
    switch (op){
        case '(': case ')': return 0;
        case '-': case '+': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void toend(char sic[]){
    init_stack_c();
    init_stack_d();
    result[0]='\0';
    int i = 0;
    while(sic[i]!='\0'){
        char c[2];
        c[0] = sic[i++];
        c[1] = '\0';
        if(c[0]>='0' && c[0]<='9') strcat(result, c);
        else if(c[0]=='(') push_c(c[0]);
        else if(c[0]==')'){
            while(!is_c_empty()){
                char op[2];
                op[0]=pop_c();
                op[1]='\0';
                if(op[0]=='(') break;
                else strcat(result, op);
            }
        }
        else if(c[0]=='+' || c[0]=='-' || c[0]=='*' || c[0]=='/'){
            while(is_c_empty() == 0){
                char op[2];
                op[0] = peek_c();
                op[1] = '\0';
                if (precedence(c[0])<=precedence(op[0])){
                    strcat(result, op);
                    pop_c();
                }
                else break;
            }
            push_c(c[0]);
        }
    }
    while (is_c_empty()==0){
        char i[2];
        i[0] = pop_c();
        i[1] = '\0';
        strcat(result, i);
    }
}

void cul(){
    double a, b, val=0;
    for(int i = 0 ; result[i]!='\0' ; i++){
        if(result[i]>='0' && result[i]<='9') push_d((double)result[i]-'0');
        else if(result[i] == '+'){
            b=pop_d();
            a=pop_d();
            push_d(a+b);
        } else if(result[i] == '-'){
            b=pop_d();
            a=pop_d();
            push_d(a-b);
        } else if(result[i] == '*'){
            b=pop_d();
            a=pop_d();
            push_d(a*b);
        } else if(result[i] == '/'){
            b=pop_d();
            a=pop_d();
            push_d(a/b);
        }
    }
    printf("수식결과 : ==> %f\n", pop_d());
}

int check(char a[]){
    for (int i = 0; a[i]!='\0'; i++){
        if(a[i]=='(' || a[i]=='{' || a[i]=='[') push_c(a[i]);
        else if(a[i]==')' || a[i]=='}' || a[i]==']'){
            if(is_c_empty()) return 2;
            if((a[i]==')' && peek_c()!='(') || (a[i]=='}' && peek_c()!='{') || (a[i]==']' && peek_c()!='[')) return 3;
            pop_c();
        }
    } 
    if(!is_c_empty()) return 1;
    else return 0;
}

int main(){
    int iserr;
    char sic[1][50];
    while(1){
        char sic[1][50];
        printf("\n CALC(Infix수식입력) 'exit'입력시 종료 >> ");
        scanf("%s", &sic);
        if(strcmp(sic[0], "exit")==0){
            printf("프로그램을 종료합니다");
            exit(1);
        }
        init_stack_c();
        init_stack_d();
        iserr=check(sic[0]);
        printf("입력수식 : %s", sic);
        if(iserr==0) printf("\n");
        else printf(" ==> 오류(조건%d 위반)\n", iserr);
        toend(sic[0]);
        printf("후위수식 : ==> %s\n", result);
        cul();
    }
    
    return 0;
}
