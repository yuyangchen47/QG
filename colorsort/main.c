#include<stdio.h>

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