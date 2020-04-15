#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>

//declare a function that can add element to queue
void enterqueue(AQueue *Q, int sizes);

int main() {
	AQueue Q;
	//create a AQueue
	InitAQueue(&Q);
	int e,size;
	enterqueue(&Q, 1);
	enterqueue(&Q, 1);
	//show the current AQueue 
	TraverseAQueue(&Q, APrint);
	printf("************ѡ�����***************\n");
	printf("������������1	TO	������������������ӡ�������������|\n");
	printf("������������2	TO	�������������������ӡ�������������|\n");
	printf("������������3	TO	�������������ж϶����Ƿ�Ϊ�ա�����|\n");
	printf("������������4	TO	�����������ж϶����Ƿ����ˡ�������|\n");
	printf("������������5	TO	���������������в���ӡ����---����-|\n");
	printf("������������6	TO	�������������õ���ͷԪ�ء���������|\n");
	printf("������������7	TO	�������������������г��ȡ���������|\n");
	printf("������������8	TO	����������������ն��С�����������|\n");
	printf("������������9	TO	���������������ݻٶ��С�����������|\n");
	printf("��������***-1	TO	���������������������˳�����������|\n");
	printf("please enter a number to select what you want to do:\n");
	int num;
	while (1)
	{
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:printf("1.int,2.char,3.double\n");  /*select the type of new element*/
			scanf_s("%d", &size);
			enterqueue(&Q, size);
			break;
		case 2:DeAQueue(&Q);
			break;
		case 3:if (IsEmptyAQueue(&Q))
			printf("the queue is empty\n");
			   else
			printf("the queue is not empty\n");
			break;
		case 4: if (IsFullAQueue(&Q))
			printf("the queue is full\n");
				else
			printf("the queue is not full\n");
			break;
		case 5: TraverseAQueue(&Q, APrint);
			break;
		case 6:	GetHeadAQueue(&Q, &e);
			printf("%d", e);
			break;
		case 7: LengthAQueue(&Q);
			break;
		case 8:ClearAQueue(&Q);
			break;
		case 9:DestoryAQueue(&Q);
			break;
		default:printf("please enter a number from 1 to 9");
			break;
		}
		if (num == -1) /*when enter -1,break*/
			break;
	}
	DestoryAQueue(&Q);
	return 0;
}
//a function to add new element
/*when entering 1,the type of new element is int
when entering 2,the type of new element is char
when entering 3,the type of new element is double*/
void enterqueue(AQueue *Q, int sizes) {
	switch (sizes)
	{
	case 1: {
		int a;
		printf("please enter a number\n");
		scanf_s("%d", &a);
		EnAQueue(Q, &a);
		break;
		}
	case 2: {
		char a;
		printf("please enter a number\n");
		scanf_s("%c", &a);
		EnAQueue(Q, &a);
		break;
		}
	case 3: {
		double a;
		printf("please enter a number\n");
		scanf_s("%lf", &a);
		EnAQueue(Q, &a);
		break;
		}
	
	}
}
