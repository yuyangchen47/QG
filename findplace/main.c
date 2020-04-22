#include<stdio.h>
#include<stdlib.h>

/*快速排序枢纽存放*/
int Partition(int *a, int begin, int end) {
	int temp = a[begin];
	int mark = begin;
	if (begin < end) {
		for (int i = begin + 1; i <= end; i++) {
			if (a[i] < temp) {
				mark++;
				int p = a[mark];
				a[mark] = a[i];
				a[i] = p;
			}
		}
		a[begin] = a[mark];
		a[mark] = temp;
		return mark;
	}
	return 0;
}

/*快速排序递归*/
void QuickSort_Recursion(int *a, int begin, int end) {
	if (begin < end) {
		int k = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, k - 1);
		QuickSort_Recursion(a, k + 1, end);
	}
}

/*在一个无序序列中找到第K大/小的数*/
int FindSize(int *a, int size, int K) {
	int begin = 0;
	int end = size - 1;
	int mark = Partition(a, begin, end);
	if (mark == K)
		return a[mark];
	else if (mark < K) {
		QuickSort_Recursion(a, mark + 1, end);
		return a[K];
	}
	else {
		QuickSort_Recursion(a, begin, mark);
		return a[K];
	}
}

int main() {
	int a[12] = { 11,5,16,91,3,87,0,8,44,71,56,28 };
	 int b = FindSize(a, 12, 5);
	 printf("the fifth element is %d", b);
	 system("pause");
	return 0;
}