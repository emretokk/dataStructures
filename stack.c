#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
	int top;
	int arr[10];
};

void push(struct stack *s, int x){
	s->top += 1;
	s->arr[s->top] = x;
}

bool stack_empty(struct stack *s){
	if(s->top==-1)
		return true;
	else return false;
}

int pop(struct stack *s){
	if(stack_empty(s)){
		printf("Stack empty\n");
		return -1;
	}
	else {
		s->top-=1;
		return s->arr[s->top+1];
	}
}

int main()
{
	struct stack *s = (struct stack *) malloc(sizeof(struct stack));
	s->top = -1;

	push(s,3);
	push(s,4);
	push(s,5);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", s->arr[i]);
	}

	printf("Popped : %d\n", pop(s));
	printf("Popped : %d\n", pop(s));
	printf("Popped : %d\n", pop(s));

	return 0;
}