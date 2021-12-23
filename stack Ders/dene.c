/*
 * dene.c
 *
 *  Created on: Aug 4, 2020
 *      Author: root
 */

#include <stdio.h>
#include "stack.h"


int main(){
	int x;
	stack s1;
	stack *s;
	s=&s1;
	s->top=0;
	push(s,4);
	push(s,5);
	x=pop(s);
	x=pop(s);
	x=pop(s);
}
