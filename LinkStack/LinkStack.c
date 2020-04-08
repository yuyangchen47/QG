#include"LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
//initialization 
Status initLStack(LinkStack *s) {
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top )
		return ERROR;
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//whether the stack is empty
Status isEmptyLStack(LinkStack *s) {
	if (s->count == 0)
		return SUCCESS;
	else
		return ERROR;
}

//clean LStack
Status clearLStack(LinkStack *s) {
	LinkStackPtr p, q;
	p = s->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	s->count = 0;
	return SUCCESS;
}


//push an element in the stack
Status pushLStack(LinkStack *s, ElemType data) {
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
//将新结点赋值给栈顶指针
	s->top = p;
	s->count++;
	return SUCCESS;
}

//delete the top element of the stack and assign it to data
Status popLStack(LinkStack *s, ElemType *data) {
//judge a linkstack 
	if (!s)
		return ERROR;
	LinkStackPtr q;
	*data = s->top->data;
//将栈顶结点赋值给q
	q = s->top;
	s->top = s->top->next;
	free(q);
	s->count--;
	return SUCCESS;
}
//print the top stack element
Status getTopLStack(LinkStack *s, ElemType *e) {
	if (s->count == 0)
		return ERROR;
	*e = s->top->data;
	printf("The top element is %d", *e);
	return SUCCESS;
}

//destroy LStack
Status destroyLStack(LinkStack *s) {
	LinkStackPtr p, q;
	p = s->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	s->top = NULL;
	return SUCCESS;
}

//print the length of LinkStack
Status LStackLength(LinkStack *s, int *length) {
	length = &(s->count);
	printf("the length of LinkStack is %d", *length);
	return SUCCESS;
}