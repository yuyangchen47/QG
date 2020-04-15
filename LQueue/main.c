#include"LQueue.h"
#include<stdio.h>
#include<stdlib.h>

/*a function to add new element*/
void enterqueue(LQueue *Q, int sizes);
int main() {
	LQueue Q;
	InitLQueue(&Q);
	int e, size;
	enterqueue(&Q, 1);
	enterqueue(&Q, 1);
	TraverseLQueue(&Q, LPrint);
	printf("************僉夲荷恬***************\n");
	printf("！！！！！！1	TO	！！！！！！！！秘錦！！！！！！！|\n");
	printf("！！！！！！2	TO	！！！！！！！！竃錦！！！！！！！|\n");
	printf("！！！！！！3	TO	！！！！！！登僅錦双頁倦葎腎！！！|\n");
	printf("！！！！！！4	TO	！！！！演煽錦双旺嬉咫！！---！！-|\n");
	printf("！！！！！！5	TO	！！！！！！誼欺錦遊圷殆！！！！！|\n");
	printf("！！！！！！6	TO	！！！！！！！！錦双海業！！！！！|\n");
	printf("！！！！！！7	TO	！！！！！！！賠腎錦双！！！！！！|\n");
	printf("！！！！！！8	TO	！！！！！！！丸支錦双！！！！！！|\n");
	printf("！！！！***-1	TO	！！！！！！！！！！曜竃！！！！！|\n");
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
		case 2:DeLQueue(&Q);
			break;
		case 3:if (IsEmptyLQueue(&Q))
			printf("the queue is empty\n");
			   else
			printf("the queue is not empty\n");
			break;
		case 4: TraverseLQueue(&Q, LPrint);
			break;
		case 5:	GetHeadLQueue(&Q, &e);
			printf("%d", e);
			break;
		case 6: LengthLQueue(&Q);
			break;
		case 7:ClearLQueue(&Q);
			break;
		case 8:DestoryLQueue(&Q);
			break;
		default:printf("please enter a number from 1 to 8");
			break;
		}
		if (num == -1) /*when enter -1,break*/
			break;
	}
	DestoryLQueue(&Q);
	return 0;
}

/*when sizes is 1,the type of value is int
when sizes is 2,the type of value is char
when sizes is 3,the type of value is double*/
void enterqueue(LQueue *Q, int sizes) {
	switch (sizes)
	{
	case 1: {
		int a;
		printf("please enter a number\n");
		scanf_s("%d", &a);
		EnLQueue(Q, &a);
		break;
		}
	case 2: {
		char a;
		printf("please enter a number\n");
		scanf_s("%c", &a,1);
		EnLQueue(Q, &a);
		break;
		}
	case 3: {
		double a;
		printf("please enter a number\n");
		scanf_s("%lf", &a);
		EnLQueue(Q, &a);
		break;
		}
	}
}
