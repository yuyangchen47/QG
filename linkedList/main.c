#include <stdio.h>
#include <stdlib.h>
#include"linkedList.h"

//declare a function
void visit(ElemType e);
LNode* create_LNode(ElemType data);

int main(){
	//create a LinkedList
	LinkedList L;
	InitList(&L);
	ElemType choice,value,e;
	LNode *midNode;

	LNode *p = create_LNode(7);
	LNode *q = create_LNode(2);
	LNode *r = create_LNode(1);
	LNode *s = create_LNode(9);

	InsertList(L, s);
	InsertList(L, r);
	InsertList(L, q);
	InsertList(L, p);
	//Traverse the current LinkedList
	printf("当前链表为：");
	TraverseList(L, visit);

	//the functions of a LinkedList
	printf("*************************请选择以下功能**************************\n");
	printf("|————--输入   &&    功能----————————————————|\n");
	printf("-————————————————————-———————————|\n");
	printf("-------------1	TO	判断队列是否循环--—————————————|\n");
	printf("-------------2	TO	删除某结点后结点并且返回删除节点值----------|\n");
	printf("-------------3	TO	反转队列元素----------——————————--|\n");
	printf("-------------4	TO	查找链表，判断是否存在某元素----------------|\n");
	printf("-------------5	TO	查找中间结点--------------------------------|\n");
	printf("-------------6	TO	交换奇偶元素--———————————————|\n");
	printf("-------------7	TO	销毁队列-—————————————————-|\n");
	printf("************-1	TO	退出------------—————————————--|\n");
	printf("请输入相应的数字进行操作：");
	while (1) {
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: if (IsLoopList(L))
					printf("这是循环链表\n");
				else
					printf("这不是循环链表\n");
				break;
		case 2: if (DeleteList(p, &e)) {
					printf("被删除的值为：%d\n", e);
					TraverseList(L, visit);
				}
				else {
					printf("删除失败\n");
					TraverseList(L, visit);
				}
				break;
		case 3: if (ReverseList(&L)) {
					printf("成功逆转，当前链表为");
					TraverseList(L, visit);
				}
				else
					printf("逆转失败\n");
				break;
		case 4: printf("请输入一个元素：");
				scanf_s("%d", &value);
				SearchList(L, value);
				break;
		case 5: midNode = FindMidNode(&L);
				printf("中间结点是%d\n", midNode->data);
				break;
		case 6:printf("交换奇偶位元素后\n");
				L = ReverseEvenList(&L);
				TraverseList(L, visit);
				break;
		case 7:printf("链表已销毁，请输入-1退出程序");
				DestroyList(&L);
				break;
		default:
			printf("有效操作请输入1-7，退出输入-1\n");
		}
		if (choice == -1)
			break;
	}
	system("pause");
	return 0;
}
// a function of creating LNodes
LNode* create_LNode(ElemType data) {
	LNode* new_node = (LNode*)malloc(sizeof(struct LNode));
	if (new_node == NULL)
		return NULL;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
