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
	printf("***************栈的功能***************\n");
	printf("|------------————————————|\n");
	printf("|------1---   TO    ---判断栈是否为空|\n");
	printf("|------2---   TO    -----得到栈顶元素|\n");
	printf("|------3---   TO    -------------入栈|\n");
	printf("|------4---   TO    -------------出栈|\n");
	printf("|------5---   TO    -----打印栈的长度|\n");
	printf("|------6---   TO    -----------清空栈|\n");
	printf("|------7---   TO    -----------销毁栈|\n");
	printf("|------8---   TO    -------退出------|\n");
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
