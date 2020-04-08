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

 //���ɽ�㣬���������� 
Status InitList(LinkedList *L) {
	*L = (LinkedList)malloc(sizeof(struct LNode));
	if (!(*L)) {
		return ERROR;  //�ڴ����ʧ�ܣ����ش���
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

 //�ݻ����� 
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
 //������ 
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
//ɾ�����
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
//����������ӡ
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
//Ѱ��ĳ����
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
		printf("��������%d���Ԫ��", e);
	else
		printf("���Ҳ�����Ԫ��");
	return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//��ת����
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
//�ж��Ƿ�Ϊѭ������,��������ָ�룬һ����ָ��һ����ָ��
//��Ϊѭ���������������ָ�������
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

//��ż����
LNode* ReverseEvenList(LinkedList *L) {
	if ((*L) == NULL && (*L)->next == NULL)
		return (*L);
	LNode *pre, *cur, *Next;		
	pre = (*L)->next;
	(*L)->next = pre->next;
	while (pre && pre->next) {
		cur = pre->next;
		Next = cur->next;
		if (cur->next && cur->next->next) {			//���cur->next�����ڣ�������Ϊż��
			pre->next = cur->next->next;			//���cur->next->next�����ڣ�������Ϊ����
		}
		else {										//��������ڣ�����δ����
			pre->next = cur->next;
		}
		cur->next = pre;							//��ż����㷴ת
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

//Ѱ���м��㣬�ȱ���һ��ȷ������Ԫ�ظ���
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
