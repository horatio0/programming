#include <stdio.h>
#include <malloc.h>

int main(){
    char *a;
    int b,i;
    scanf("%d", &b);
    a=(char*)malloc(sizeof(char)*b);
    fgets(a,b,stdin);
    for(i=0;i<=b;i++) printf("%c", a[i]);
}