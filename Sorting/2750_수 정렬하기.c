#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1001];

//스와프
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//퀵정렬
void quick_sort(int start, int end) {
	//원소가 1개인 경우
	if (start >= end)
		return;
	//피벗
	int pivot = start;
	int left = pivot + 1;
	int right = end;

	while (left <= right) {
		//피벗값보다 큰 값을 찾을 때 까지
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		//반대로 작은 값을 찾을 때 까지
		while (right > start && arr[right] >= arr[pivot])
			right--;
		if (left > right)
			swap(&arr[pivot], &arr[right]);
		else
			swap(&arr[left], &arr[right]);
	}
	quick_sort(start, right - 1);
	quick_sort(right + 1, end);
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	
	quick_sort(0,n-1);

	for (int i = 0; i < n; i++) 
		printf("%d\n", arr[i]);
	
	return 0;
}