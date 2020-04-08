#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"

int main() {
	SqStack S;
	ElemType e,data;
	int i, length, menu;
	initStack(&S,50);

	pushStack(&S, 3);
	pushStack(&S, 2);
	pushStack(&S, 1);
	stackLength(&S, &length);
	printf("\n");
	// the operations of sqstack
	printf("***************ջ�Ĺ���***************\n");
	printf("|------------������������������������|\n");
	printf("|------1---   TO    ---�ж�ջ�Ƿ�Ϊ��|\n");
	printf("|------2---   TO    -----�õ�ջ��Ԫ��|\n");
	printf("|------3---   TO    -------------��ջ|\n");
	printf("|------4---   TO    -------------��ջ|\n");
	printf("|------5---   TO    -----��ӡջ�ĳ���|\n");
	printf("|------6---   TO    -----------���ջ|\n");
	printf("|------7---   TO    -----------����ջ|\n");
	printf("|------8---   TO    -------�˳�------|\n");
	printf("please input a number to select operation:\n");

	while (1)
	{
		scanf_s("%d", &menu);
		switch (menu)
		{
		case 1:if (isEmptyStack(&S))
			printf("The SqStack is empty!\n");
			   else
			printf("The SqStack is not empty!\n");
			break;
		case 2: getTopStack(&S, &e);
			break;
		case 3:printf("please enter a number");
			scanf_s("%d", &i);
			pushStack(&S, i);
			break;
		case 4: popStack(&S, &data);
			break;
		case 5:stackLength(&S, &length);
			break;
		case 6:if (clearStack(&S))
			printf("The stack has been cleaned!\n");
			   else
			printf("Unsuccessfully\n");
			break;
		case 7:printf("The stack will be destroyed\n");
			destroyStack(&S);
			break;
		default:printf("The valid numbers are from 1 to 7\nplease enter a right number\n");
			break;
		}
		if (menu == 8)
			break;
	}
	return 0;
}
