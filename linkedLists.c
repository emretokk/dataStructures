#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *prev;
	int data;
	struct node *arka;
};

struct node* head;

void addNode(int val){
	struct node *new = (struct node *) malloc(sizeof(struct node));
	new->data = val;
	// IF LIST IS EMPTY ADD TO THE FRONT
	if (head == NULL)
	{
		new->arka = NULL;
		new->prev = NULL;
		head = new;
	}
	// UNLESS ADD TO BACK
	else{
		struct node *gez = head;
		while(gez->arka != NULL){
			gez = gez->arka;
		}
		gez->arka = new;
		new->prev = gez;
		new->arka = NULL;
	}
}

void deleteNode(int removeVal){
	struct node* gez = head;
	struct node* pptr = NULL;
	while(gez->data != removeVal && gez != NULL){
		pptr = gez;
		gez = gez->arka;
	}
	pptr->arka = gez->arka;
	gez->arka->prev = pptr;
	free(gez);
}

int main()
{
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);

	deleteNode(3);

	struct node* gez = head;
	while (gez != NULL){
		printf("%d ", gez->data);
		gez = gez->arka;
	}

	return 0;
}