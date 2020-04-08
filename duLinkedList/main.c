#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"
//declare a function
void print(ElemType e); 
DuLinkedList create_DuLNode(ElemType data);
int main() {
	//initialize a DuLinkedList
	DuLinkedList L;
	InitList_DuL(&L);
	ElemType e;
	//create a DuLinkedList and insert DuLNodes
	DuLNode *p = create_DuLNode(7);
	DuLNode *q = create_DuLNode(2);
	DuLNode *r = create_DuLNode(1);
	DuLNode *s = create_DuLNode(9);
	InsertAfterList_DuL(L, s);
	InsertBeforeList_DuL(s, r);
	InsertBeforeList_DuL(r, q);
	InsertBeforeList_DuL(q, p);
	//traverse the current DuLinkedList
	printf("当前链表为：");
	//print the DuLNode from the next DuLNode in the head DuLNode
	TraverseList_DuL(L->next, print);
	printf("\n");
	if (DeleteList_DuL(p, &e))
		printf("被删除结点里元素的值是%d\n", e);
	else
		printf("删除失败");
	printf("现在链表值为：");
	TraverseList_DuL(L->next, print);
	printf("\n");
	DestroyList_DuL(&L);
	system("pause");
	return 0;
}

void print(ElemType e) {
	printf("%d", e);
}
// a functions to increase DuLNodes
DuLinkedList create_DuLNode(ElemType data) {
	DuLinkedList new_node = (DuLinkedList)malloc(sizeof(struct  DuLNode));
	if (new_node == NULL)
		return NULL;
	new_node->data = data;
	new_node->prior = NULL;
	new_node->next = NULL;
	return new_node;
}