#include <stdio.h>

int main() {
    int start, end, i, j, count=0;
    printf("Please set your start number and end number\nstart number : ");
    scanf_s("%d", &start);
    printf("end number : ");
    scanf_s("%d", &end);
    for (i = start; i <= end; i++) {
        for (j = 2; j <= i; j++) {
            if (i <= j) {
                printf("%d\t", i);
                count++;
            }
            if (i % j == 0) break;            
        }
        if (count == 5) {
            printf("\n");
            count = 0;

        }
    }
}