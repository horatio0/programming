typedef int TElement;
#include "TreeLinked.h"
#define VisitNode(n) (printf("%d ", (n)->data))
#define KEY(n) (n->data)

TNode* search_bst(TNode* root, int key){
    if(root==NULL) return NULL;
    if(KEY(root)==key) return root;
    else if(key < KEY(root)) return search_bst(root->left,key);
    else return search_bst(root->right,key);
}

void insert_bst(TNode* root, TNode* n){
    if(KEY(n)<KEY(root)){
        if(root->left==NULL) root->left = n;
        else insert_bst(root->left,n);
    }else if(KEY(n) > KEY(root)){
        if(root->right==NULL) root->right = n;
        else insert_bst(root->right,n);
    }
    else free(n);
}

TNode* delete_bst(TNode* root, int key){
    TNode* n=root;
    TNode* parent = NULL;
    while(n!=NULL && key!=KEY(n)){
        parent = n;
        n = (key < KEY(n)) ? n->left : n->right;
    }
    if(n==NULL) return root;
    if((n->left==NULL && n->right == NULL)){
        if(parent==NULL) root=NULL;
        else{
            if(parent->left == n) parent->left = NULL;
            else parent->right = NULL;
        }
        free(n);
    }else if(n->left==NULL||n->right==NULL){
        TNode * child = (n->left!=NULL) ? n->left : n->right;
        if(n==root) root=child;
        else{
            if(parent->left==n) parent->left = child;
            else{
                if(parent->left==n) parent->left = child;
                else parent->right = child;
            }
            free(n);
        }
    }
    return root;
}

void preorder(TNode* n)
{
    if (n != NULL) {
        VisitNode(n);
        preorder(n->left);
        preorder(n->right);
    }
}

// �׽�Ʈ ���α׷�: 10���� ��带 ������ �� Ž���� ���� ����
int main(void)
{
    int keys[] = { 35, 18, 7, 26, 12, 3, 68, 22, 30, 99 };

    // ���� ���� �׽�Ʈ
    TNode* root = create_tree(keys[0], NULL, NULL);
    for (int i = 1; i < 10; i++) {
        TNode* n = create_tree(keys[i], NULL, NULL);
        insert_bst(root, n);
        printf("\n ���� %2d: ", keys[i]);
        preorder(root);
    }
    printf("\n");

    // Ž�� ���� �׽�Ʈ
    TNode* n = search_bst(root, 26);
    printf("26 Ž��: %s\n", (n != NULL) ? "����" : "����");
    n = search_bst(root, 25);
    printf("25 Ž��: %s\n", (n != NULL) ? "����" : "����");

    // ���� ���� �׽�Ʈ
    root = delete_bst(root, 3);
    printf("\ncase1: < 3> ����: ");
    preorder(root);
    root = delete_bst(root, 68);
    printf("\ncase2: <68> ����: ");
    preorder(root);
    root = delete_bst(root, 18);
    printf("\ncase3: <18> ����: ");
    preorder(root);
    root = delete_bst(root, 35);
    printf("\ncase3: <35> root: ");
    preorder(root);
}
