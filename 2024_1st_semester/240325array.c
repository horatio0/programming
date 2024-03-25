#include <stdio.h>

void reset_variable(int a){
    a=0;
}
void reset_array(int a[], int len){
    for (int i = 0;i<len;i++) a[i]=0;
}

int main(){
    int A[3] = {10, 20, 30}, x=2024;

    reset_variable(x);
    reset_array(A, 3);
    
    printf("변수 초기화 : x=%d\n", x);
    printf("배열 초기화 : ");
    for (int i=0;i<3;i++) printf("A[%d]=%d\n", i, A[i]);
    return 0;
}