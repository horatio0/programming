#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
	char    name[200];
	char    num[200];
} TElement;

typedef struct{
	int age;
	char sex;
	char rela[21];
	char memo[101];
} minfo;

#include "TreeLinked.h"
TNode*  no_call = NULL;

TElement get_elem(char* name, char* num)
{
	TElement e;
	strcpy_s(e.name, 200, name);
	strcpy_s(e.num, 200, num);
	return e;
}

TNode* search_bst(TNode* root, char* key, int mode)
{
	if (root == NULL) return NULL;

	if (mode == 0){ // 이름 검색 모드
		int diff = strcmp(key, root->data.name);
	    if (diff == 0) return root;
	    else if (diff < 0)
		    return search_bst(root->left, key, 0);
	    else
		    return search_bst(root->right, key, 0);
	} else if(mode == 1) { // 즐겨찾기=1 검색 모드
		if(root->isFavorites == 1) printf(" ★%10s: %s\n", root->data.name, root->data.num);
		search_bst(root->left, key, 1);
		search_bst(root->right, key, 1);
	} else if(mode==2){ // 즐겨찾기=0 검색 모드
		if(root->isFavorites == 0) printf("   %10s: %s\n", root->data.name, root->data.num);
		search_bst(root->left, key, 2);
		search_bst(root->right, key, 2);
	}
	return NULL;
}

void insert_bst(TNode* root, TNode* n)
{
	int diff = strcmp(n->data.name, root->data.name);

	if (diff < 0) {
		if (root->left == NULL)
			root->left = n;
		else insert_bst(root->left, n);
	}
	else if (diff > 0) {
		if (root->right == NULL)
			root->right = n;
		else insert_bst(root->right, n);
	}
	else free(n);
}

TNode* delete_bst(TNode* root, char* key)
{
	TNode* n = root;
	TNode* parent = NULL;
	while (n != NULL && strcmp(key, n->data.name) != 0) {
		parent = n;
		n = (strcmp(key, n->data.name) < 0) ? n->left : n->right;
	}
	if (n == NULL) return root;

	if ((n->left == NULL && n->right == NULL)) {
		if (parent == NULL) root = NULL;
		else {
			if (parent->left == n) parent->left = NULL;
			else parent->right = NULL;
		}
		free(n);
	}

	else if (n->left == NULL || n->right == NULL) {
		TNode* child = (n->left != NULL) ? n->left : n->right;
		if (n == root) root = child;
		else {
			if (parent->left == n) parent->left = child;
			else parent->right = child;
		}
		free(n);
	}

	else {
		TNode* succ = n->right;
		while (succ->left != NULL)
			succ = succ->left;
		n->data = succ->data;
		n->right = delete_bst(n->right, succ->data.name);
	}
	return root;
}
void preorder(TNode* n)
{
	if (n != NULL) {
		if(n->isFavorites == 0) printf("   %10s: %s\n", n->data.name, n->data.num);		
		preorder(n->left);
		preorder(n->right);
	}
}

void fav(TNode* root){
	char c, name[200];
	printf("즐겨찾기 등록(i), 즐겨찾기 삭제(d): ");
	c = _getche();
	printf("\n");
	switch (c){
		case 'i':{
            printf("  > 현재 즐겨찾기 등록되지 않은 인물:\n");
			search_bst(root, NULL, 2);
			printf("  > 즐겨찾기에 등록할 새로운 인물:");
			scanf_s("%s", name, 200);
			TNode *p = search_bst(root, name, 0);
			p->isFavorites = 1;
			printf("  > 등록 완료\n");
			break;
		}
		case 'd':{
			printf("  > 즐겨찾기에서 삭제할 인물:");
			scanf_s("%s", name, 200);
			TNode *p = search_bst(root, name, 0);
			p->isFavorites = 0;
			printf("  > 삭제 완료\n");
			break;
		}
	}
}
void no(minfo r){
	char c, num[200], name[200];
	printf("  > 차단 목록:\n");
	preorder(no_call);
	printf("차단 등록(i), 차단 해제(d): ");
	c = _getche();
	printf("\n");
	switch (c){
		case 'i':{
			printf("  > 차단 할 대상의 이름과 번호:");
			scanf_s("%s%s", name, 200, num, 200);
			TNode* n = create_tree(get_elem(name, num), r, NULL, NULL);
			if (no_call==NULL) no_call=n;
			else insert_bst(no_call,n);
			printf("  > 등록 완료\n");
			break;
		}
		case 'd':{
			printf("  > 차단 해제할 대상의 이름:");
			scanf_s("%s", name, 200);
			no_call = delete_bst(no_call, name);
			break;
		}
	}
}
int main(void)
{
	char	command2,command, name[200], phone[200];
	TNode*	root = NULL;
	minfo reset;
	reset.age=0;
	strcpy(reset.memo, "입력되지 않음");
	reset.sex = 'N';
	strcpy(reset.rela, "입력되지 않음");

	do {
		printf("입력(i), 검색(s), 삭제(d), 변경(c), 자세한 정보(m), 즐겨찾기(f), 차단(n), 전체 출력(p), 초기화(a), 종료(q): "); //추가정보
		command = _getche();
		printf("\n");
		switch (command) {
		case 'm':{
			printf("  > 어떤 인물의 정보를 찾으십니까?:");
			scanf_s("%s", name, 200);
			TNode *p = search_bst(root,name,0);
			printf("  > 현재 등록된 해당 인물의 정보입니다.\n  > 나이 : %d\n  > 성별 : %c\n  > 관계 : %s\n  > 메모 : %s\n", p->info.age, p->info.sex, p->info.rela, p->info.memo);
			printf("  > 정보 변경(c), 나가기(e): ");
			command2 = _getche();
			if(command2=='c'){
	    		printf("\n  > 순차적으로 입력해 주세요:\n  > 나이: ");
		    	scanf("%d", &p->info.age);
			    rewind(stdin);
			    printf("  > 성별 (M/F): ");
			    scanf("%c", &p->info.sex);
			    printf("  > 관계: ");
			    scanf_s("%s", p->info.rela, 20);
			    printf("  > 메모: ");
			    scanf_s("%s", p->info.memo, 100);
			    printf("\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n  > 변경된 해당 인물의 정보입니다.\n  > 나이 : %d\n  > 성별 : %c\n  > 관계 : %s\n  > 메모 : %s\n  > 저장완료\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n", p->info.age, p->info.sex, p->info.rela, p->info.memo);
			    break;
			} else if(command2=='e') {printf("\n"); break;}
		}
		case 'n':{
			no(reset);
			break;
		}
		case 'f':{
			fav(root);
			break;
		}
		case 'a':{
			delete_tree(root);
			delete_tree(no_call);
			no_call = NULL;
			root = NULL;
			printf("  > 초기화 완료.\n");
			break;
		}
		case 'c':{
		    printf("  > 변경할 이름 검색:");
			scanf_s("%s", name, 200);
			TNode* p = search_bst(root, name, 0);
			if(p!=NULL){
				printf("  > 새로운 이름과 전화번호 입력: ");
				scanf_s("%s%s", name, 200, phone, 200);
				strcpy(p->data.name, name);
				strcpy(p->data.num, phone);
			}
			break;
		}
		case 'i':
		{
			printf("  > 등록할 이름과 전화번호: ");
			scanf_s("%s%s", name, 200, phone, 200);
			TNode* n = create_tree(get_elem(name, phone), reset, NULL, NULL);
			if (root == NULL) root = n;
			else insert_bst(root, n);
			break;
		}
		case 'd':
		{
			printf("  > 삭제할 이름: ");
			scanf_s("%s", name, 200);
			root = delete_bst(root, name);
			break;
		}
		case 's':
		{
			printf("  > 검색할 이름: ");
			scanf_s("%s", name, 200);
			TNode* p = search_bst(root, name, 0);
			if (p != NULL)
				printf("  > %s해당 이름의 번호: %s\n", name, p->data.num);
			break;
		}
		case 'p':
		{
			printf("  > 전체출력: \n");
			if(root==NULL) printf("데이터가 없습니다.\n");
			else {
				search_bst(root, NULL, 1);
				preorder(root);
			}
			break;
		}
		case 'q':
			exit(0);
		}
	} while (command != 'q');
}