#include <stdio.h>

void ht(int n, char from, char tmp, char to){
    if(n==1) printf("원판 1: %c --> %c\n", from, to);
    else{
        ht(n-1, from, to, tmp);
        printf("원판 %d: %c --> %c\n", n, from, to);
        ht(n-1, tmp, from, to);
    }
}
int main(){
    ht(50, 'A', 'B', 'C');
    return 0;
}