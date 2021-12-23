#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *top;

void push(int data){
	struct Node *new = (struct Node *) malloc(sizeof(struct Node));

	if (!new)
	{
		printf("Stack Overflow");
		exit(1);
	}
	new->data = data;
	new->next = top;
	top = new;
}

int isEmpty()
{
    return top == NULL;
}

int pop(){
	if (top == NULL)
	{
		printf("Stack Underflow");
        exit(1);
	}
	else{
		struct Node *temp;
		temp = top;

		int x = temp->data;
        // Assign second node to top
		top = top->next;
		// Destroy connection between
        // first and second
		temp->next = NULL;
		// Release memory of top node
		free(temp);
		return x;
	}
}

int main()
{
	struct Node *root;
	root = top;

	push(11);
	push(22);
	push(33);
	push(44);

	int x;
	x = pop();

	struct Node *gez;
	gez = top;
	while(gez != NULL){
		printf("%d\n", gez->data);
		gez = gez->next;
	}
	printf("\n%d\n", x);
	return 0;
}