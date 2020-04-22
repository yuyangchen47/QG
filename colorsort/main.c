#include<stdio.h>

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

int main() {
	int a[12] = { 0,2,1,2,0,1,1,2,0,1,1,2};
	for (int i = 0; i < 12; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	ColorSort(a, 12);
	for (int j = 0; j < 12; j++) {
		printf("%d ", a[j]);
	}
	system("pause");
	return 0;
}