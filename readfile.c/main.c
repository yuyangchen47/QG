#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"readnum.h"
int main() {
	/*写入文件*/
	FILE *fpWrite = fopen("data.txt", "w");
	if (fpWrite) {
		int a[12] = { 0 };
		srand((unsigned)time(NULL));
		for (int i = 0; i < 12; i++) {
			a[i] = rand();
			fprintf(fpWrite, "%d ", a[i]);
		}
		fclose(fpWrite);
	}
	else
		printf("无法打开文件");
	/*读取文件*/
	int n = 0;
	int i = 0;
	int arr[12] = { 0 };
	int temp[12] = { 0 };
	FILE *fp = fopen("data.txt","r");
	if (fp == NULL) {
		printf("error");
	}
	while (fscanf(fp, "%d",&n) != EOF) {
		arr[i] = n;
		i++;
	}
	fclose(fp);
	printf("\n");
	for (int k = 0; k < 6; k++) {
		switch (k)
		{
		case 0:insertSort(arr, 12);
			for (int j = 0; j < 12; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
			break;
		case 1:MergeSort(arr, 0, 11, temp);
			for (int j = 0; j < 12; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
			break;
		case 2:QuickSort_Recursion(arr, 0, 11);
			for (int j = 0; j < 12; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
			break;
		case 3:QuickSort(arr, 12);
			for (int j = 0; j < 12; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
			break;
		case 4: CountSort(arr, 12, 0);
			for (int j = 0; j < 12; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
			break;
		case 5:RadixCountSort(arr, 12);
			for (int j = 0; j < 12; j++) {
				printf("%d ", arr[j]);
			}
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
