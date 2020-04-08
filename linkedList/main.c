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
	printf("��ǰ����Ϊ��");
	TraverseList(L, visit);

	//the functions of a LinkedList
	printf("*************************��ѡ�����¹���**************************\n");
	printf("|��������--����   &&    ����----��������������������������������|\n");
	printf("-����������������������������������������-����������������������|\n");
	printf("-------------1	TO	�ж϶����Ƿ�ѭ��--��������������������������|\n");
	printf("-------------2	TO	ɾ��ĳ�����㲢�ҷ���ɾ���ڵ�ֵ----------|\n");
	printf("-------------3	TO	��ת����Ԫ��----------��������������������--|\n");
	printf("-------------4	TO	���������ж��Ƿ����ĳԪ��----------------|\n");
	printf("-------------5	TO	�����м���--------------------------------|\n");
	printf("-------------6	TO	������żԪ��--������������������������������|\n");
	printf("-------------7	TO	���ٶ���-����������������������������������-|\n");
	printf("************-1	TO	�˳�------------��������������������������--|\n");
	printf("��������Ӧ�����ֽ��в�����");
	while (1) {
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: if (IsLoopList(L))
					printf("����ѭ������\n");
				else
					printf("�ⲻ��ѭ������\n");
				break;
		case 2: if (DeleteList(p, &e)) {
					printf("��ɾ����ֵΪ��%d\n", e);
					TraverseList(L, visit);
				}
				else {
					printf("ɾ��ʧ��\n");
					TraverseList(L, visit);
				}
				break;
		case 3: if (ReverseList(&L)) {
					printf("�ɹ���ת����ǰ����Ϊ");
					TraverseList(L, visit);
				}
				else
					printf("��תʧ��\n");
				break;
		case 4: printf("������һ��Ԫ�أ�");
				scanf_s("%d", &value);
				SearchList(L, value);
				break;
		case 5: midNode = FindMidNode(&L);
				printf("�м�����%d\n", midNode->data);
				break;
		case 6:printf("������żλԪ�غ�\n");
				L = ReverseEvenList(&L);
				TraverseList(L, visit);
				break;
		case 7:printf("���������٣�������-1�˳�����");
				DestroyList(&L);
				break;
		default:
			printf("��Ч����������1-7���˳�����-1\n");
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
