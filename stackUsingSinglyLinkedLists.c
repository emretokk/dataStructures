#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int stackCount=0;

void push(struct node* top, int data){
	if (stackCount == 0)
	{
		top->data = data;
		top->next = NULL;
	}
	else{
		struct node* new = (struct node*) malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;
		top->next = new;
		top = new;
	}
	stackCount+=1;
}
 
int main(int argc, char const *argv[])
{
	struct node* root;
	struct node* head = root;

	push(head, 11);
	push(head, 22);
	push(head, 33);
	push(head, 44);

	// struct node* gez = root;
	// while(gez!=NULL){
	// 	printf("%d\n", gez->data);
	// 	gez = gez->next;
	// }
	return 0;
}