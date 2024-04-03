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
    printf("수식 : %s = %1f\n\n", result, pop_d());
}

int main(){
    init_stack_c();
    init_stack_d();
    char sic[1][50];
    printf("\n STACK(Postfix수식 입력=>값출력) >> ");
    scanf("%s", &sic);
    toend(sic[0]);
    cul();
    return 0;
}
