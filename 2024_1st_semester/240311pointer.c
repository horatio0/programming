#include <stdio.h>
#include <string.h>

int main(){
    int y[5] = {50,40,30,20,10}, *z[]={y+4,y+3,y+2,y+1,y};
    int **pz;
    pz=z;
    printf("%d %d", **z, **pz);
}