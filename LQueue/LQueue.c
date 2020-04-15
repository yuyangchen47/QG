#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

/*create a LQueue*/
void InitLQueue(LQueue *Q) {
	Node *p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
		return;
	p->next = NULL;
	Q->front = Q->rear = p;
	Q->length = 30;
	printf("初始化成功\n");
	return;
}

void DestoryLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return;
	ClearLQueue(Q);
	free(Q->rear);
	free(Q->front);
	return;
}

Status IsEmptyLQueue(const LQueue *Q){
	if (Q->front == Q->rear)
		return TRUE;
	return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e) {
	if (Q == NULL)    
		return FALSE;
	memcpy(e, Q->front->next->data, 10);
	return TRUE;
}

int LengthLQueue(LQueue *Q) {
	int length;
	Node *q = (Node*)malloc(sizeof(Node));
	q = Q->front;
	for (length = 0; q != Q->rear; length++) {
		q = q->next;
	}
	printf("%d", length);
	return 0;
}

Status EnLQueue(LQueue *Q, void *data) {
	Node *p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void *)malloc(Q->length);
	if (NULL == p->data)
		return FALSE;
	memcpy(p->data,data,Q->length);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

Status DeLQueue(LQueue *Q) {
	if (Q == NULL)
		return FALSE;
	Node*p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (!Q->front->next)
		Q->rear = Q->front;
	free(p);
	return TRUE;
}

void ClearLQueue(LQueue *Q) {
	if (!Q)
		return;
	Node *s, *q;
	Q->rear = Q->front;
	s = Q->front->next;
	while (s != NULL) {
		q = s;
		s = s->next;
		free(q);
	}
	free(s);
	return;
}

Status TraverseLQueue(const LQueue *Q, void(*foo)(void *q,int sizes)) {
	if (!Q)
		return FALSE;
	Node* p = (void *)malloc(Q->length);
	p = Q->front->next;
	int i = 1;
	while (p != NULL)
	{
		if (i % 5 == 0)
			printf("\n");
		foo(p->data,sizeof(p->data));
		p = p->next;
		i++;
	}
	printf("\n");
	return TRUE;
}

/*judge the type by sizes and print the value*/
void LPrint(void *q,int sizes) {
	if (sizes == sizeof(double))
		printf("%lf", *(double *)q);
	if (sizes == sizeof(int))
		printf("%d", *(int *)q);
	if (sizes == sizeof(char))
		printf("%c", *(char *)q);
	printf("-<");
}