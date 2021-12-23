#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *pre;
	int data;
	struct node *next;
};

struct node* head;

void addNode(int val){
	struct node *new = (struct node *) malloc(sizeof(struct node));
	new->data = val;
	// IF LIST IS EMPTY ADD TO THE FRONT
	if (head == NULL)
	{
		new->next = NULL;
		new->pre = NULL;
		head = new;
	}
	// UNLESS ADD TO BACK
	else{
		struct node *gez = head;
		while(gez->next != NULL){
			gez = gez->next;
		}
		gez->next = new;
		new->pre = gez;
		new->next = NULL;
	}
}

void deleteNode(int removeVal){
	struct node* gez = head;
	while(gez->data != removeVal && gez != NULL){
		gez=gez->next;
	}
	if (gez = NULL)
	{
		printf("ELEMAN BULUNAMADI");
	}
	else{
		// LISTEDE 1 ELEMAN VAR 
		if (gez->next == NULL)
		{
			int tmpData = gez->data;
			gez->data = 0;
			free(gez);
		}
		// SONDAN CIKARMA
		else if (gez->next == NULL && gez->pre != NULL)
		{
			int tmpData = gez->data;
			gez->data = 0;
			gez->pre->next = NULL;
			gez->pre = NULL;
			free(gez);
		}
		// ARADAN CIKARMA
		else{
			printf("aAAAAA");
			int tmpData = gez->data;
			gez->data = 0;
			gez->pre->next = gez->next;
			gez->next->pre = gez->pre;
			gez->pre = NULL;
			gez->next = NULL;
		}
	}
}

int main()
{
	addNode(78);
	addNode(32);
	addNode(12);
	addNode(123);
	addNode(23);

	deleteNode(23);
	
	struct node* gez = head;
	while (gez != NULL){
		printf("%d ", gez->data);
		gez = gez->next;
	}

	return 0;
}