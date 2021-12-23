/*
 * stack.c
 *
 *  Created on: Aug 4, 2020
 *      Author: root
 */
#include <stdio.h>
#include "stack.h"

bool stack_empty(stack *s){
	if(s->top==0)
			return true;
	else return false;
}

void push(stack *s, int x){
	s->top=s->top+1;
	s->sk[s->top]=x;
	printf("push: value: %d s.top=%d\n",x, s->top);
}

int pop(stack *s){
	if(stack_empty(s)){
		printf("Stack empty\n");
		return -1;
	}
	else {
		s->top=s->top-1;
		printf("pop:  value:%d s.top:%d\n",s->sk[s->top+1], s->top);
		return s->sk[s->top+1];
	}
}
