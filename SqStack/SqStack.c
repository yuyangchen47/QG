#include<stdio.h>
#include"SqStack.h"
#include<stdlib.h>

//initialization 
Status initStack(SqStack *s, int sizes) {
	if (!s)
		return ERROR;
	s->elem = malloc(sizeof(ElemType)*sizes);
	s->top = -1;
	s->size = sizes;
	printf("initializate sucessfully!\n");
	return SUCCESS;
}

//whether the stack is empty
Status isEmptyStack(SqStack *s) {
	if (s && (s->top == -1))
		return SUCCESS;
	else
		return ERROR;
}

//destroy a stack
Status destroyStack(SqStack *s) {
	free(s->elem);
	return SUCCESS;
}

//print the top stack element
Status getTopStack(SqStack *s, ElemType *e) {
	if ((!s) || (s->top == -1))
		return ERROR;
	*e = s->elem[s->top];
	printf("The top stack element is %d",*e);
	return SUCCESS;
}

//clear a stack
Status clearStack(SqStack *s) {
	if (!s)
		return ERROR;
	s->top = -1;
	return SUCCESS;
}

//print the length of the sqstack
Status stackLength(SqStack *s, int *length) {
	if ((!s) || (s->top == -1))
		return ERROR;
	//int i = sizeof(s->elem) / sizeof(s->top);
	int i = s->top + 1;
	length = &i;
	printf("the length of a SqStack is %d", *length);
	return SUCCESS;
}
//push an element in the stack
Status pushStack(SqStack *s, ElemType data) {
	//judge whether the stack is empty
	if (s->top == s->size - 1)
		return ERROR;
	else {
		//s->top++;
		s->elem[++s->top] = data;
		return SUCCESS;
	}
}

//delete the top element of the stack and assign it to data
Status popStack(SqStack *s, ElemType *data) {
	if (s->top == -1)
		return ERROR;
	*data = s->elem[s->top];
	s->top--;
	printf("The deleted element is %d", *data);
	return SUCCESS;
}