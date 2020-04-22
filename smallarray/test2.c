#include"test2.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*��������*/
void insertSort(int *a, int n) {
	int i;
	for (i = 1; i < n; i++) {    /*������n��Ԫ��*/
		if (a[i] < a[i - 1]) {
			int t = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] > t) {     
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = t;   /*����Ҫ�����Ԫ��*/
		}
	}
}

/*�鲢��������*/
void MergeArray(int *a, int begin, int mid, int end, int *temp) {
	int i = begin, j = mid + 1;
	int m = mid, n = end;
	int k = 0;
	/*�ϲ���������*/
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	/*����������ʣ�µ�Ԫ�ز�������temp*/
	while (i <= m) {
		temp[k++] = a[i++];
	}
	while (j <= n)
	{
		temp[k++] = a[j++];
	}
	/*������temp��Ԫ����һ����������a*/
	for (i = 0; i < k; i++) {
		memcpy(a, temp, (end - begin + 1) * sizeof(int));
	}
}

/*�鲢����ָ��*/
void MergeSort(int *a, int begin, int end, int *temp) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		MergeSort(a, begin, mid, temp); /*�������*/
		MergeSort(a, mid + 1, end, temp);/*�ұ�����*/
		MergeArray(a, begin, mid, end, temp);
	}
}

/*����������Ŧ���*/
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

/*��������ݹ�*/
void QuickSort_Recursion(int *a, int begin, int end) {
	if (begin < end) {
		int k = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, k - 1);
		QuickSort_Recursion(a, k + 1, end);
	}
}

/*��������ǵݹ��*/
void QuickSort(int *a, int size) {
	int tmpsize = (int)log((double)size) / log((double)2);
	int *stack = (int *)malloc(sizeof(int)*tmpsize * 2);//���ٶ�̬�ռ�
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

/*��������*/
void CountSort(int *a, int size, int max) {
	int min = a[0];
	max = min;
	int j, i;
	/*�ҵ������Сֵ*/
	for (i = 0; i < size; i++) {
		if (a[i] < min)
			min = a[i];
		if (a[i] >= max)
			max = a[i];
	}
	/*Ϊ����������ռ�*/
	int *cnt = (int*)malloc(sizeof(int)*(max - min + 1));
	if (cnt == NULL)
		return;
	for (i = 0; i < max - min + 1; i++) {
		cnt[i] = 0;
	}
	/*Ϊ�����������ռ�*/
	int *temp = (int*)malloc(sizeof(int)*size);
	if (temp == NULL)
		return;
	/*ͳ��ÿ��Ԫ�صĳ��ִ���*/
	for (j = 0; j < size; j++) {
		cnt[a[j] - min] = cnt[a[j] - min] + 1;
	}
	/*��Ԫ�ر���Ĵ���������ǰһ��Ԫ�صĴ������õ�Ԫ��ƫ����*/
	for (i = 1; i < max - min + 1; i++) {
		cnt[i] += cnt[i - 1];
	}
	/*��Ԫ������ķ�����������*/
	for (i = size - 1; i >= 0; i--) {
		cnt[a[i] - min] -= 1;
		temp[cnt[a[i] - min]] = a[i];
	}
	/*���������е�Ԫ�����򿽱���ԭ��������*/
	memcpy(a, temp, size * sizeof(int));
	/*�ͷ�ǰ�����Ŀռ�*/
	free(temp);
	free(cnt);
}

/*������������*/

int RadixSort(int *index, int *a, int size) {
	int *cnt = (int*)malloc(sizeof(int) * 10); /*�����������*/
	for (int i = 0; i < 10; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		++cnt[index[i]];	/*�������������ʼ����������*/
	}
	for (int i = 1; i < 10; ++i) {
		cnt[i] += cnt[i - 1];		/*���ƫ����*/
	}
	int *Sort = (int*)malloc(sizeof(int)*size); /*�����������*/
	/*�������*/
	for (int i = size - 1; i >= 0; --i) {
		--cnt[index[i]];
		Sort[cnt[index[i]]] = a[i];
	}
	/*���źõ����ݷ���ԭ��������*/
	for (int i = 0; i < size; i++) {
		a[i] = Sort[i];
	}
	free(Sort);
	free(cnt);
	return 1;
}
void RadixCountSort(int *a, int size) {
	/*����Ż����Ŀռ�*/
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

/*��ɫ����*/
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void ColorSort(int *a, int size) {
	int left = 0;/*ָ���ʼλ��*/
	int right = size - 1;/*ָ��ĩβλ��*/
	int cur = 0;
	while (cur <= right) {
		if (a[cur] == 0) {
			swap(&a[cur], &a[left]);
			left++;  /*����Ԫ��0������ָ�붼Ҫ����*/
			cur++;
		}
		else if (a[cur] == 2) {
			swap(&a[cur], &a[right]);/*����Ԫ��2��rightҪ��ǰ�ƣ���curָ�벻������*/
			right--;				/*�п��ܽ�����Ԫ��Ϊ0����Ҫ�����ж�*/
		}
		else
			cur++;
	}
}

/*��һ�������������ҵ���K��/С����*/
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
