#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
	struct node* parent;
}node;

node* createNode(int val){
	node* new = (node*) malloc(sizeof(node));
	new->value = val;
	new->right = NULL;
	new->left = NULL;
	new->parent = NULL;
	return new;
}

void insertNode(node* root, node* new){
	node *y = NULL;
	node *x = root;
	while (x != NULL){
		y = x;
		if (new->value <= x->value)
		{
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	new->parent = y;
	// tree is empty
	if (y == NULL)
	{
		root = new;
	}
	// smaller
	else if (new->value <= y->value)
	{
		y->left = new;
	}
	else // greater or equal
	{
		y->right = new;
	}
}

void preorderTreeWalk(node* root){
	if (root != NULL)
	{
		printf("%d ", root->value);
		preorderTreeWalk(root->left);
		preorderTreeWalk(root->right);
	}
 }

void inorderTreeWalk(node* root){
	if (root != NULL)
	{
		inorderTreeWalk(root->left);
		printf("%d ", root->value);
		inorderTreeWalk(root->right);
	}
}

void postorderTreeWalk(node* root){
	if (root != NULL)
	{
		postorderTreeWalk(root->left);
		postorderTreeWalk(root->right);
		printf("%d ", root->value);
	}
}

node* treeSearchRecursive(node* root, int searchVal){
	if (root == NULL || root->value == searchVal)
	{
		return root;
	}
	if (searchVal <= root->value)
	{
		return treeSearchRecursive(root->left, searchVal);
	}
	else{
		return treeSearchRecursive(root->right, searchVal);
	}
}

node* treeSearchIterative(node* root, int searchVal){
	node* gez = root;
	while (gez != NULL && gez->value != searchVal){
		if (searchVal <= gez->value)
		{
			gez = gez->left;
		}
		else{
			gez = gez->right;
		}
	}
	return gez;
}

node* treeMinumum(node* root){
	node* gez = root;
	while (gez->left != NULL){
		gez = gez->left;
	}
	return gez;
}

node* treeMaximum(node* root){
	node* gez = root;
	while (gez->right != NULL){
		gez = gez->right;
	}
	return gez;
}

node* treeSuccessor(node* x){
	if (x->right != NULL)
	{
		return treeMinumum(x->right);
	}
	node* y = x->parent;
	while (y != NULL && x == y->right){
		x = y;
		y = y->parent;
	}
	return y;

}

void TRANSPLANT(node* root, node* u, node* v){
	if (u->parent == NULL)
	{
		root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else{
		u->parent->right = v;
	}
	if (v != NULL)
	{
		v->parent = u->parent;
	}
}

void deleteNode(node* root, node* z){
	if (z->left == NULL)
	{
		TRANSPLANT(root, z, z->right);
	}
	else if (z->right == NULL)
	{
		TRANSPLANT(root, z, z->left);		
	}
	else{
		node* y = treeMinumum(z->right);
		if (y->parent != z)
		{
			TRANSPLANT(root, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		TRANSPLANT(root, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}

int main(void)
{
	node* root = createNode(5);
	node* tempNode = createNode(7);

	insertNode(root, createNode(3));
	insertNode(root, tempNode);
	insertNode(root, createNode(2));
	insertNode(root, createNode(5));
	insertNode(root, createNode(8));

	preorderTreeWalk(root);

	deleteNode(root, tempNode);

	printf("\n\n");
	preorderTreeWalk(root);

	return 0;
}