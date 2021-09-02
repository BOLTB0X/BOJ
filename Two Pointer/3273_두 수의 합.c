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
	if (start >= end) return; //원소가 1개인 경우
	int pivot = start; //피벗은 첫 번째 원소
	int left = start + 1;
	int right = end;
	while (left <= right) {
		//피벗보다 큰 데이터를 찾을 때까지 반복
		while (left <= end && arr[left] <= arr[pivot]) 
			left++;
		// 피벗보다 작은 데이터를 찾을 때까지 반복
		while (right > start && arr[right] >= arr[pivot]) 
			right--;
		// 엇갈렸다면 작은 데이터와 피벗을 교체
		if (left > right) 
			swap(&arr[pivot], &arr[right]);
		// 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
		else swap(&arr[left], &arr[right]);
	}
	// 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
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