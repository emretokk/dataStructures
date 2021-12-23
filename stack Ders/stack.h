/*
 * stack.h
 *
 *  Created on: Aug 4, 2020
 *      Author: root
 */

#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

typedef struct st{
	int top;
	int size;
	int sk[100];
}stack;

bool stack_empty(stack *s);

void push(stack *s, int x);

int pop(stack *s);


#endif /* STACK_H_ */
