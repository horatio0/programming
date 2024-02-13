//행맨
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char family[7] = "family";
char helloworld[11] = "helloworld";
char lose[5] = "lose";
char win[4] = "win";
char star[11] = "**********";
int len = 0, word, wrong = 0;

void setting() {
    srand(time(NULL));
    word = rand() % 4;  //단어 선택
    switch (word) {
    case 0:
        len = 6;
        break;
    case 1:
        len = 10;
        break;
    case 2:
        len = 4;
        break;
    case 3:
        len = 3;
        break;
    }
}

void print() {
    int i;
    switch (wrong) {
    case 0:
        for (i = 0; i < len; i++) printf("%c", star[i]);
        printf("\n\t  ┌ㅡㅡㅡㅡ┐\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        break;
    case 1:
        for (i = 0; i < len; i++) printf("%c", star[i]);
        printf("\n\t  ┌ㅡㅡㅡㅡ┐\n");
        printf("\t  ○       ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        break;
    case 2:
        for (i = 0; i < len; i++) printf("%c", star[i]);
        printf("\n\t  ┌ㅡㅡㅡㅡ┐\n");
        printf("\t  ○       ㅣ\n");
        printf("\t  │       ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        break;
    case 3:
        for (i = 0; i < len; i++) printf("%c", star[i]);
        printf("\n\t  ┌ㅡㅡㅡㅡ┐\n");
        printf("\t  ○       ㅣ\n");
        printf("\t ┌│       ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        break;
    case 4:
        for (i = 0; i < len; i++) printf("%c", star[i]);
        printf("\n\t  ┌ㅡㅡㅡㅡ┐\n");
        printf("\t  ○       ㅣ\n");
        printf("\t ┌│┐      ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        break;
    case 5:
        for (i = 0; i < len; i++) printf("%c", star[i]);
        printf("\n\t  ┌ㅡㅡㅡㅡ┐\n");
        printf("\t  ○       ㅣ\n");
        printf("\t ┌│┐      ㅣ\n");
        printf("\t /        ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        break;
    case 6:
        printf("\n\t  ┌ㅡㅡㅡㅡ┐\n");
        printf("\t  ○       ㅣ\n");
        printf("\t ┌│┐      ㅣ\n");
        printf("\t /\\       ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        printf("\t          ㅣ\n");
        break;
    }
}

void judge(char in) {
    switch (word) {
    case 0:
        if (in == 'f') star[0] = 'f';
        else if (in == 'a') star[1] = 'a';
        else if (in == 'm') star[2] = 'm';
        else if (in == 'i') star[3] = 'i';
        else if (in == 'l') star[4] = 'l';
        else if (in == 'y') star[5] = 'y';
        else wrong++;
        break;
    case 1:
        if (in == 'h') star[0] = 'h';
        else if (in == 'e') star[1] = 'e';
        else if (in == 'w') star[5] = 'w';
        else if (in == 'r') star[7] = 'r';
        else if (in == 'd') star[9] = 'd';
        else if (in == 'l') {
            star[2] = 'l';
            star[3] = 'l';
            star[8] = 'l';
        }
        else if (in == 'o') {
            star[4] = 'o';
            star[6] = 'o';
        }
        else wrong++;
        break;
    case 2:
        if (in == 'l') star[0] = 'l';
        else if (in == 'o') star[1] = 'o';
        else if (in == 's') star[2] = 's';
        else if (in == 'e') star[3] = 'e';
        else wrong++;
        break;
    case 3:
        if (in == 'w') star[0] = 'w';
        else if (in == 'i') star[1] = 'i';
        else if (in == 'n') star[2] = 'n';
        else wrong++;
        break;
    }
}

int main() {
    int count = 0;
    char input="";
    setting();
    while (count < 6) {
        system("cls");
        print();
        printf("입력 : ");
        scanf_s("%c", &input, 1);
        rewind(stdin);
        judge(input);
        count++;
    }
    if (count == 6) {
        system("cls");
        printf("틀렸습니다!\n");
        print();
    }
    return 0;
}