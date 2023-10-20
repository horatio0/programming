#include<stdio.h>
#include<math.h>

double cul();
void mem();
double memory = 0;
double lg();
double sq();
int memq = 1;
int exit = 0;
double fact();

int main(void) {
	double result;
	char a;
	printf("ㅡㅡㅡㅡㅡㅡ계산기ㅡㅡㅡㅡㅡㅡ\n수식 중간에 p입력시 원주율(3.14)로 계산\n수식 중간에 e입력시 자연상수(2.71)로 계산\n수식 중간에 m입력시 메모리에 저장된 수로 계산\n수식 입력칸에 L 입력시 로그 계산\n수식 입력칸에 ^ 입력시 제곱 계산\n");
	printf("수식 입력칸에 c입력시 메모리에 저장된 수 확인\n수식 입력칸에 !입력시 팩토리얼 계산\n");
	while (1) {
		printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n수식을 입력하시오 : ");
		result = cul();
		if (exit==1) break;
		if (memq == 1) {
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n계산 결과는 %f입니다\n", result);
			mem(result);
		}
		else if (memq == 0) {
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n메모리에 저장된 값은 %f입니다\n", result);
			printf("메모리를 초기화 하시겠습니까?   Y/N  : ");
			scanf_s(" %c", &a, 1);
			if (a == 'Y' || a == 'y') {
				memory = 0;
				printf("정상적으로 초기화 되었습니다\n");
			}
			else printf("초기화 하지 않았습니다\n");
			memq = 1;
		}
	}
}

double cul() {                     //수식 계산 함수
	char fo[100] = { '0' };
	double num[50] = { 0 };
	char sign[50];
	int a, b, fcount = 0, sp = 0, count = 0, c, scount = 0;
	scanf_s("%s", &fo, 100);
	if (fo[0] == 'c' || fo[0] == 'C') {
		memq = 0;
		return memory;
	}
	else if (fo[0] == 'l' || fo[0] == 'L') return lg();
	else if (fo[0] == '^') return sq();
	else if (fo[0] == '!') return fact();
	else if (fo[0]=='`'){
		exit = 1;
		return 0;
	}
	else {
		for (a = 0; a < 50; a++) {
			for (b = sp; b < 100; b++) {
				if (fo[b] == '+' || fo[b] == '-' || fo[b] == '*' || fo[b] == '/' || fo[b] == '\0') {
					sign[a] = fo[b];
					break;
				}
				if (fo[b] == '.') {
					fcount++;
					for (c = b + 1; c < 50; c++) {
						if (fo[c] == '+' || fo[c] == '-' || fo[c] == '*' || fo[c] == '/' || fo[c] == '\0') {
							sign[a] = fo[c];
							break;
						}
						num[count + 1] = (num[count + 1] * 10) + ((double)fo[c] - 48);
						scount++;
						fcount++;
					}
					for (c = 0; c < scount; c++) {
						num[count + 1] = num[count + 1] / 10;
					}
					num[count] = num[count] + num[count + 1];
					num[count + 1] = 0;
					scount = 0;
					break;
				}
				if (fo[b] == 'e' || fo[b] == 'E') num[count] = 2.71;
				else if (fo[b] == 'p' || fo[b] == 'P') num[count] = 3.14;
				else if (fo[b] == 'm' || fo[b] == 'M') num[count] = memory;
				else num[count] = (num[count] * 10) + ((double)fo[b] - 48);
				fcount++;
			}
			sp = sp + fcount + 1;
			fcount = 0;
			count++;
			if (sign[a] == '\0') break;
		}
		for (a = 0; a < 50; a++) {
			if (sign[a] == '*') {
				num[a] = num[a] * num[a + 1];
				for (b = a + 1; b < 50; b++) {
					num[b] = num[b + 1];
					sign[b - 1] = sign[b];
					if (sign[b] == '\0') break;
				}
				a--;
			}
			else if (sign[a] == '/') {
				num[a] = num[a] / num[a + 1];
				for (b = a + 1; b < 50; b++) {
					num[b] = num[b + 1];
					sign[b - 1] = sign[b];
					if (sign[b] == '\0') break;
				}
				a--;
			}
			else if (sign[a] == '\0') break;
		}
		for (a = 0; a < 50; a++) {
			if (sign[a] == '+') {
				num[a] = num[a] + num[a + 1];
				for (b = a + 1; b < 50; b++) {
					num[b] = num[b + 1];
					sign[b - 1] = sign[b];
					if (sign[b] == '\0') break;
				}
				a--;
			}
			else if (sign[a] == '-') {
				num[a] = num[a] - num[a + 1];
				for (b = a + 1; b < 50; b++) {
					num[b] = num[b + 1];
					sign[b - 1] = sign[b];
					if (sign[b] == '\0') break;
				}
				a--;
			}
		}
		return num[0];
	}
}

void mem(double a) {
	char b;
	while (1) {
		printf("해당 값을 메모리에 저장하시겠습니까?   Y/N  : ");
		scanf_s(" %c", &b, 1);
		if (b == 'Y' || b == 'y') {
			printf("+ : 메모리에 더하기\n- : 메모리에 빼기\n= : 메모리에 덮어쓰기\n기호를 입력하시오 : ");
			scanf_s(" %c", &b, 1);
			while (1) {
				if (b == '+') {
					memory = memory + a;
					printf("정상적으로 처리되었습니다. 현재 메모리 값 : %f\n", memory);
					break;
				}
				else if (b == '-') {
					memory = memory - a;
					printf("정상적으로 처리되었습니다. 현재 메모리 값 : %f\n", memory);
					break;
				}
				else if (b == '=') {
					memory = a;
					printf("정상적으로 처리되었습니다. 현재 메모리 값 : %f\n", memory);
					break;
				}
				else printf("\'+\' 또는 \'-\' 또는 \'=\' 만 입력하여 주십시오 \n");
			}
			break;
		}
		else if (b == 'n' || b == 'N') {
			printf("저장하지 않았습니다\n");
			break;
		}
		else printf("Y 또는 N 으로 입력해 주십시오.\n");
	}
}


double lg() {         //로그 계산 함수
	int an;
	double mit, zinsu;
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("원하는 로그 선택\n\n1. 로그\n2. 자연로그\n3. 상용로그\n\n원하는 로그의 번호 입력 : ");
	scanf_s("%d", &an);
	if (an == 1) {
		printf("밑 입력 : ");
		scanf_s("%lf", &mit);
		printf("진수 입력 : ");
		scanf_s("%lf", &zinsu);
		return logf(zinsu) / logf(mit);
	}
	else if (an == 2) {
		printf("진수 입력 : ");
		scanf_s("%lf", &zinsu);
		return logf(zinsu);
	}
	else if (an == 3) {
		printf("진수 입력 : ");
		scanf_s("%lf", &zinsu);
		return log10f(zinsu);
	}
}

double sq() {
	double mit, zisu, a, i;
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");                            //제곱 계산 함수
	printf("밑 입력 : ");
	scanf_s("%lf", &mit);
	printf("지수 입력 : ");
	scanf_s("%lf", &zisu);
	a = mit;
	for (i = 1; i < zisu; i++) mit = mit * a;
	return mit;
}

double fact() {         //팩토리얼 계산 함수
	int z,y,x=1;
	printf("정수 입력(13! 부터는 오류) : ");
	scanf_s(" %d",&z);
	for (y = 1; y <= z;y++) {
		x = x * y;
	}
	return x;
}