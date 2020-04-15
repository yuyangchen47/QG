#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//create 
void InitAQueue(AQueue *Q) {
	int i;
	Q->length = MAXQUEUE;
	for (i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void *)malloc(Q->length);
	Q->front = Q->rear = 0;
}

//DestoryAQueue
void DestoryAQueue(AQueue *Q) {
	if (Q->data[0] == NULL)
		return;
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	Q->data[0] = NULL;
	return;
}

//FullAQueue
Status IsFullAQueue(const AQueue *Q){
	if (IsEmptyAQueue(Q)) {
		return FALSE;
	}
	if ((Q->rear + 1) % MAXQUEUE == Q->front)
		return TRUE;
	else
		return FALSE;
}

//IsEmptyAQueue
Status IsEmptyAQueue(const AQueue *Q){
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

//GetHeadAQueue
Status GetHeadAQueue(AQueue *Q, void *e) {
	//whether AQueue is empty
	if (Q->front == Q->rear)
		return FALSE;
	else {
		int i = Q->front;
		i = (i + 1) % MAXQUEUE;
		memcpy(e, Q->data[i], Q->length);
		return TRUE;
	}
}

//LengthAQueue
int LengthAQueue(AQueue *Q) {
	printf("the length of queue is %d", (Q->rear - Q->front + Q->length) % Q->length);
	return 0;
}

//InAQueue
Status EnAQueue(AQueue *Q, void *data) {
	// AQueue is full
	if (IsFullAQueue(Q))
	{
		return FALSE;
	}
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	memcpy(Q->data[Q->rear], data, Q->length);
	return TRUE;
}

//DeAQueue
Status DeAQueue(AQueue *Q) {
	if (Q->rear == Q->front)
		return FALSE;
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}

//ClearAQueue
void ClearAQueue(AQueue *Q) {
	Q->front = Q->rear = 0;
	return;
}

//TraverseAQueue
Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q,int sizes)) {
	if (Q->front == Q->rear)
		return FALSE;
	int i = 0;
	while (i < (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE)
	{
		foo(Q->data[Q->front+i+1],sizeof(Q->data[Q->front + i+1]));
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}


//change void *q to other styles 
//print the value properly
void APrint(void *q,int sizes) {
	if (sizes == sizeof(double))
		printf("%lf", *(double *)q);
	if (sizes == sizeof(int))
		printf("%d", *(int *)q);
	if (sizes == sizeof(char))
		printf("%c", *(char *)q);
	printf("-<");
}