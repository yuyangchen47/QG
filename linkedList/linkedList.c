#include"linkedList.h"
#include<stdio.h>
#include<stdlib.h>


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

 //生成结点，创建空链表 
Status InitList(LinkedList *L) {
	*L = (LinkedList)malloc(sizeof(struct LNode));
	if (!(*L)) {
		return ERROR;  //内存分配失败，返回错误
	}
	(*L)->next = NULL;
	return SUCCESS;
}


/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */

 //摧毁链表 
void DestroyList(LinkedList *L) {
	LinkedList p,q;
	p = (*L)->next;
	while (p){
		q = p->next;
		free(p);
		p = q;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
 //插入结点 
Status InsertList(LNode *p, LNode *q) {
	if (p == NULL)
		return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
//删除结点
Status DeleteList(LNode *p, ElemType *e) {
	if (!p || !p->next)
		return ERROR;
	LNode *q;
	q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return SUCCESS;
} 

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
//遍历链表并打印
void TraverseList(LinkedList L, void(*visit)(ElemType e)) {
	LinkedList p = L->next;
	while (p){ 
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}
void visit(ElemType e)
{
	printf("%d ", e);
}


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
//寻找某个数
Status SearchList(LinkedList L, ElemType e) {
	if (L->next == NULL)
		return ERROR;
	int flag = 0;
	LNode *p = L->next;
	while (p) {
		if (p->data == e) {
			flag = 1;
			break;
		}
		else
			p = p->next;
	}
	if (flag)
		printf("链表中有%d这个元素", e);
	else
		printf("查找不到该元素");
	return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//反转链表
Status ReverseList(LinkedList *L) {
	if (!(*L) || !(*L)->next)		return ERROR;	LNode *p, *q, *temp;	p = (*L)->next;	(*L)->next = NULL;	q = temp = NULL;	while (p) {		q = p->next;		p->next = temp;		temp = p;		p = q;	}	(*L)->next = temp;
	return SUCCESS;
}


/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//判断是否为循环链表,定义两个指针，一个快指针一个慢指针
//若为循环链表则最后两个指针会相遇
Status IsLoopList(LinkedList L) {
	LNode *fast, *slow;
	fast = slow = L;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */

//奇偶调换
LNode* ReverseEvenList(LinkedList *L) {
	if ((*L) == NULL && (*L)->next == NULL)
		return (*L);
	LNode *pre, *cur, *Next;		
	pre = (*L)->next;
	(*L)->next = pre->next;
	while (pre && pre->next) {
		cur = pre->next;
		Next = cur->next;
		if (cur->next && cur->next->next) {			//如果cur->next不存在，结点个数为偶数
			pre->next = cur->next->next;			//如果cur->next->next不存在，结点个数为奇数
		}
		else {										//如果都存在，遍历未结束
			pre->next = cur->next;
		}
		cur->next = pre;							//将偶数结点反转
		pre = Next;
	}
	return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */

//寻找中间结点，先遍历一遍确定链表元素个数
LNode* FindMidNode(LinkedList *L) {
	LNode *mid = *L;
	int count;
	for (count = 0; mid; count++) {
		mid = mid->next;
	}
	mid = *L;
	for (int i = 0; i < count / 2; i++)
		mid = mid->next;
	return mid;
}
