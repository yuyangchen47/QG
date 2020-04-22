#include"qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int a[10001] = { 0 };
	int temp[10001] = {0};
	printf("sizeof10000\n");
	for (int j = 0; j < 7; j++) {
		for (size_t i = 0; i < 10000; i++) {
			a[i] = rand();
		}
		clock_t start = clock();
		switch (j)
		{
		case 0:insertSort(a, 9999);
			clock_t diff1 = clock() - start;
			printf("插入排序所花费的时间：%dms\n", diff1);
			break;
		case 1:MergeSort(a, 0, 9999, temp);
			clock_t diff3 = clock() - start;
			printf("归并排序所花的时间：%dms\n", diff3);
			break;
		case 2:QuickSort_Recursion(a, 0,9999);
			clock_t diff4 = clock() - start;
			printf("快速排序（递归）所花的时间：%dms\n", diff4);
			break;
		case 3:QuickSort(a, 10000);
			clock_t diff5 = clock() - start;
			printf("快速排序（非递归）所花的时间：%dms\n", diff5);
			break;
		case 4: CountSort(a, 10000, 0);
			clock_t diff6 = clock() - start;
			printf("计数排序所花的时间：%dms\n", diff6);
			break;
		case 5:RadixCountSort(a, 10000);
			clock_t diff7 = clock() - start;
			printf("基数计数排序所花的时间：%dms\n", diff7);
			break;
		default:
			break;
		}
		a[10000] = 0;
		temp[10000] = 0;
	}
	printf("\n");
	
	printf("sizeof50000\n");
	int a1[50001] = { 0 };
	int temp1[50001] = { 0 };
	for (int j = 0; j < 7; j++) {
		for (size_t i = 0; i < 50000; i++) {
			a1[i] = rand();
		}
		clock_t start = clock();
		switch (j)
		{
		case 0:insertSort(a1, 49999);
			clock_t diff1 = clock() - start;
			printf("插入排序所花费的时间：%dms\n", diff1);
			break;
		case 1:MergeSort(a1, 0, 49999, temp1);
			clock_t diff3 = clock() - start;
			printf("归并排序所花的时间：%dms\n", diff3);
			break;
		case 2:QuickSort_Recursion(a1, 0,49999);
			clock_t diff4 = clock() - start;
			printf("快速排序（递归）所花的时间：%dms\n", diff4);
			break;
		case 3:QuickSort(a1, 50000);
			clock_t diff5 = clock() - start;
			printf("快速排序（非递归）所花的时间：%dms\n", diff5);
			break;
		case 4: CountSort(a1, 50000, 0);
			clock_t diff6 = clock() - start;
			printf("计数排序所花的时间：%dms\n", diff6);
			break;
		case 5:RadixCountSort(a1, 50000);
			clock_t diff7 = clock() - start;
			printf("基数计数排序所花的时间：%dms\n", diff7);
			break;
		default:
			break;
		}
		a1[50000] = 0;
		temp1[50000] = 0;
	}
	printf("\n");
	
	printf("sizeof200000\n");
	for (int j = 0; j < 6; j++) {
		int *a2 = (int *)malloc(sizeof(int) * 200001);
		if (!a2)
			return;

		int *temp2 = (int *)malloc(sizeof(int) * 200001);
		if (!temp2)
			return;
		for (size_t i = 0; i < 200000; i++) {
			a2[i] = rand();
		}
		clock_t start = clock();
		switch (j)
		{
		case 0:insertSort(a2, 200000);
			clock_t diff1 = clock() - start;
			printf("插入排序所花费的时间：%dms\n", diff1);
			free(a2);
			free(temp2);
			break;
		case 1:MergeSort(a2, 0, 199999, temp2);
			clock_t diff3 = clock() - start;
			printf("归并排序所花的时间：%dms\n", diff3);
			free(a2);
			free(temp2);
			break;
		case 2:QuickSort_Recursion(a2, 0, 199999);
			clock_t diff4 = clock() - start;
			printf("快速排序（递归）所花的时间：%dms\n", diff4);
			free(a2);
			free(temp2);
			break;
		case 3:QuickSort(a2, 200000);
			clock_t diff5 = clock() - start;
			printf("快速排序（非递归）所花的时间：%dms\n", diff5);
			free(a2);
			free(temp2);
			break;
		case 4: CountSort(a2, 200000, 0);
			clock_t diff6 = clock() - start;
			printf("计数排序所花的时间：%dms\n", diff6);
			free(a2);
			free(temp2);
			break;
		case 5:RadixCountSort(a2, 200000);
			clock_t diff7 = clock() - start;
			printf("基数计数排序所花的时间：%dms\n", diff7);
			free(a2);
			free(temp2);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

