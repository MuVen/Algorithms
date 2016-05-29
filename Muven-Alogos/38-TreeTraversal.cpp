// 38-TreeTraversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* CreateNode(int tdata) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = tdata;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printPreOrderTree(struct node* root){
	if(root == NULL)
		return;

	printf("%d\t",root->data);
	printPreOrderTree(root->left);
	printPreOrderTree(root->right);
}

void printPostOrderTree(struct node* root){
	if(root == NULL)
		return;

	printPostOrderTree(root->left);
	printPostOrderTree(root->right);
	printf("%d\t",root->data);
}

void printInOrderTree(struct node* root){
	if(root == NULL)
		return;

	printInOrderTree(root->left);
	printf("%d\t",root->data);
	printInOrderTree(root->right);
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node* root = CreateNode(1);
	root->left = CreateNode(2);
	root->right = CreateNode(3);

	root->left->left = CreateNode(4);
	root->left->right = CreateNode(5);

	root->right->left = CreateNode(6);
	root->right->right = CreateNode(7);

	printf("PreOrder:\t");printPreOrderTree(root);printf("\n");
	printf("PostOrder:\t");printPostOrderTree(root);printf("\n");
	printf("InOrder:\t");printInOrderTree(root);

	return 0;
}

