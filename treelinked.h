#include <stdio.h>
#include <stdlib.h>


typedef struct TNode {
	TElement        data;
	minfo			info;
	struct TNode*   left;
	struct TNode*   right;
	int isFavorites;
} TNode;

TNode* create_tree(TElement data, minfo reset, TNode* left, TNode* right)
{
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = data;
	n->info = reset;
	n->left = left;
	n->right = right;
	n->isFavorites = 0;
	return n;
}
void delete_tree(TNode* n)
{
	if (n != NULL) {
		delete_tree(n->left);
		delete_tree(n->right);
		free(n);
	}
}

