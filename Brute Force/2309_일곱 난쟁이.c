#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�� �Լ�
int sum(int* arr) {
	int tot = 0;
	for (int i = 0; i < 9; ++i)
		tot += arr[i];

	return tot;
}

//������
int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//������
void quick_sort(int *a, int start, int end) {
	if (start >= end) 
		return;
	//i�� ���� j�� ������, �ǹ� ���� ���� �������� ����
	int key = start, i = start + 1, j = end, temp; 
	//�������� ������ �ݺ�
	while (i <= j) { 
		//Ű���� �� ���� ������ ������
		while (i <= end && a[i] <= a[key]) 
			i++; 
		// �ݴ�� ���� ���� 
		while (j > start && a[j] >= a[key]) 
			j--;
		if (i > j) 
			swap(&a[key], &a[j]);
		else 
			swap(&a[i], &a[j]);
	}
	// ������ �� �κ��� ��������� ȣ��
	quick_sort(a, start, j - 1);
	quick_sort(a, j + 1, end);
}

int main(void) {
	int arr[9];

	for (int i = 0; i < 9; ++i) 
		scanf("%d", &arr[i]);
	
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum(arr) - arr[i] - arr[j] == 100) {
				arr[i] = 0;
				arr[j] = 0;
				break;
			}
		}
	}

	//�������� ����
	quick_sort(arr, 0, 8);
	for (int i = 0; i < 9; ++i) {
		if (arr[i] == 0)
			continue;
		printf("%d\n", arr[i]);
	}

	return 0;
}