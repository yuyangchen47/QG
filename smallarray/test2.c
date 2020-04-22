#include"test2.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*插入排序*/
void insertSort(int *a, int n) {
	int i;
	for (i = 1; i < n; i++) {    /*共插入n个元素*/
		if (a[i] < a[i - 1]) {
			int t = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] > t) {     
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = t;   /*插入要插入的元素*/
		}
	}
}

/*归并排序数组*/
void MergeArray(int *a, int begin, int mid, int end, int *temp) {
	int i = begin, j = mid + 1;
	int m = mid, n = end;
	int k = 0;
	/*合并左右数组*/
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	/*将左右数组剩下的元素插入数组temp*/
	while (i <= m) {
		temp[k++] = a[i++];
	}
	while (j <= n)
	{
		temp[k++] = a[j++];
	}
	/*将数组temp的元素逐一拷贝到数组a*/
	for (i = 0; i < k; i++) {
		memcpy(a, temp, (end - begin + 1) * sizeof(int));
	}
}

/*归并排序指针*/
void MergeSort(int *a, int begin, int end, int *temp) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		MergeSort(a, begin, mid, temp); /*左边排序*/
		MergeSort(a, mid + 1, end, temp);/*右边排序*/
		MergeArray(a, begin, mid, end, temp);
	}
}

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

/*快速排序非递归版*/
void QuickSort(int *a, int size) {
	int tmpsize = (int)log((double)size) / log((double)2);
	int *stack = (int *)malloc(sizeof(int)*tmpsize * 2);//开辟动态空间
	if (!stack)
		return;
	int begin = 0;
	int top = 0;
	int end = size - 1;
	int k = Partition(a, begin, end);
	if (k > begin + 1) {
		stack[top++] = begin;
		stack[top++] = k - 1;
	}
	if (k < end - 1) {
		stack[top++] = k + 1;
		stack[top++] = end;
	}
	while (top > 0) {
		end = stack[--top];
		begin = stack[--top];
		k = Partition(a, begin, end);
		if (k < end - 1) {
			stack[top++] = k + 1;
			stack[top++] = end;
		}
	}
	free(stack);
	stack = NULL;
}

/*计数排序*/
void CountSort(int *a, int size, int max) {
	int min = a[0];
	max = min;
	int j, i;
	/*找到最大最小值*/
	for (i = 0; i < size; i++) {
		if (a[i] < min)
			min = a[i];
		if (a[i] >= max)
			max = a[i];
	}
	/*为计数器分配空间*/
	int *cnt = (int*)malloc(sizeof(int)*(max - min + 1));
	if (cnt == NULL)
		return;
	for (i = 0; i < max - min + 1; i++) {
		cnt[i] = 0;
	}
	/*为有序数组分配空间*/
	int *temp = (int*)malloc(sizeof(int)*size);
	if (temp == NULL)
		return;
	/*统计每个元素的出现次数*/
	for (j = 0; j < size; j++) {
		cnt[a[j] - min] = cnt[a[j] - min] + 1;
	}
	/*将元素本身的次数加上它前一个元素的次数，得到元素偏移量*/
	for (i = 1; i < max - min + 1; i++) {
		cnt[i] += cnt[i - 1];
	}
	/*将元素有序的放在新数组中*/
	for (i = size - 1; i >= 0; i--) {
		cnt[a[i] - min] -= 1;
		temp[cnt[a[i] - min]] = a[i];
	}
	/*将新数组中的元素有序拷贝回原来的数组*/
	memcpy(a, temp, size * sizeof(int));
	/*释放前面分配的空间*/
	free(temp);
	free(cnt);
}

/*基数计数排序*/

int RadixSort(int *index, int *a, int size) {
	int *cnt = (int*)malloc(sizeof(int) * 10); /*保存计数个数*/
	for (int i = 0; i < 10; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		++cnt[index[i]];	/*遍历整个数组初始化计数个数*/
	}
	for (int i = 1; i < 10; ++i) {
		cnt[i] += cnt[i - 1];		/*求得偏移量*/
	}
	int *Sort = (int*)malloc(sizeof(int)*size); /*存放有序数组*/
	/*逆向遍历*/
	for (int i = size - 1; i >= 0; --i) {
		--cnt[index[i]];
		Sort[cnt[index[i]]] = a[i];
	}
	/*将排好的数据返回原来的数组*/
	for (int i = 0; i < size; i++) {
		a[i] = Sort[i];
	}
	free(Sort);
	free(cnt);
	return 1;
}
void RadixCountSort(int *a, int size) {
	/*申请放基数的空间*/
	int *temp = (int *)malloc(sizeof(int)*size);
	int base = 1;
	int flag = 1;
	while (flag) {
		base *= 10;
		flag = 0;
		for (int i = 0; i < size; i++) {
			temp[i] = a[i] % base;
			temp[i] /= base / 10;
			if (a[i] / base > 0) {
				flag = 1;
			}
		}
		RadixSort(temp, a, size);
	}
	free(temp);
}

/*颜色排序*/
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void ColorSort(int *a, int size) {
	int left = 0;/*指向初始位置*/
	int right = size - 1;/*指向末尾位置*/
	int cur = 0;
	while (cur <= right) {
		if (a[cur] == 0) {
			swap(&a[cur], &a[left]);
			left++;  /*发现元素0后两个指针都要增加*/
			cur++;
		}
		else if (a[cur] == 2) {
			swap(&a[cur], &a[right]);/*发现元素2后right要向前移，但cur指针不能增加*/
			right--;				/*有可能交换的元素为0，需要重新判断*/
		}
		else
			cur++;
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
