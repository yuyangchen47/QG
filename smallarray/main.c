#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"test2.h"
int main() {
	size_t i,j;
	int a[101] = { 0 };
	int temp[101] = { 0 };
	//clock_t start = clock();
	for (int k = 0; k < 6; k++) {
		clock_t start = clock();
		for (i = 0; i < 100000; i++) {
			for (j = 0; j < 100; j++) {
				a[j] = rand();
			}
			switch (k)
			{
			case 0:insertSort(a, 100);
				break;
			case 1:MergeSort(a, 0, 100, temp);
				break;
			case 2:QuickSort_Recursion(a, 0, 100);
				break;
			case 3:QuickSort(a, 100);
				break;
			case 4: CountSort(a, 100, 0);
				break;
			case 5:RadixCountSort(a, 100);
				break;
			default:
				break;
			}
		}
		clock_t diff = clock() - start;
		switch (k)
		{
		case 0:printf("插入排序所花费的时间：%dms\n", diff); break;
		case 1:printf("归并排序所花的时间：%dms\n", diff); break;
		case 2:printf("快速排序（递归）所花的时间：%dms\n", diff); break;
		case 3:printf("快速排序（非递归）所花的时间：%dms\n", diff); break;
		case 4:printf("计数排序所花的时间：%dms\n", diff); break;
		case 5:printf("基数计数排序所花的时间：%dms\n", diff); break;
		default:break;
		}
		a[100] = 0;
		temp[100] = 0;
	}
	system("pause");
	return 0;
}
