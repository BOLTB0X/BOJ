#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

int arr[100001];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
 }

void quickSort(int start, int end) {
	if (start >= end) return; //���Ұ� 1���� ���
	int pivot = start; //�ǹ��� ù ��° ����
	int left = start + 1;
	int right = end;
	while (left <= right) {
		//�ǹ����� ū �����͸� ã�� ������ �ݺ�
		while (left <= end && arr[left] <= arr[pivot]) 
			left++;
		// �ǹ����� ���� �����͸� ã�� ������ �ݺ�
		while (right > start && arr[right] >= arr[pivot]) 
			right--;
		// �����ȴٸ� ���� �����Ϳ� �ǹ��� ��ü
		if (left > right) 
			swap(&arr[pivot], &arr[right]);
		// �������� �ʾҴٸ� ���� �����Ϳ� ū �����͸� ��ü
		else swap(&arr[left], &arr[right]);
	}
	// ���� ���� ���� �κа� ������ �κп��� ���� ���� ����
	quickSort(start, right - 1);
	quickSort(right + 1, end);
}

int two_pointer(int arr_len, int target) {
    int start = 0, end = arr_len - 1;
	int partial_tot = 0, cnt = 0;

    quickSort(start, end);

    while (start < end) {
        partial_tot = arr[start] + arr[end];
        if (partial_tot == target) {
            cnt++;
            start++;
            end--;
        }
        else if (partial_tot < target)
            start++;
        else if (partial_tot > target)
            end--;
    }
    return cnt;
}

int main(void) {
	int n, x;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &x);

    int ret = two_pointer(n, x);
    printf("%d",ret);
    return 0;
}