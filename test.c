#include <stdio.h>

int main(){
    int h,m;
    scanf("%d", &h);
    scanf("%d", &m);
    if (m<45){
        h=h-1;
        m=45-m;
        m=60-m;
    }else{
        m=m-45;
    }
    printf("%dh %dm", h, m);
}