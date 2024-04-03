#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(){
    char a[] = "hello ";
    strcat(a, "world");
    printf("%s", &a);
}