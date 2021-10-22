#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//합 함수
int sum(int* arr) {
	int tot = 0;
	for (int i = 0; i < 9; ++i)
		tot += arr[i];

	return tot;
}

//스와핑
int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//퀵정렬
void quick_sort(int *a, int start, int end) {
	if (start >= end) 
		return;
	//i는 왼쪽 j는 오른쪽, 피벗 값을 가장 왼쪽으로 가정
	int key = start, i = start + 1, j = end, temp; 
	//엇갈리기 전까지 반복
	while (i <= j) { 
		//키보다 쿤 값을 만나기 전까지
		while (i <= end && a[i] <= a[key]) 
			i++; 
		// 반대로 작은 값을 
		while (j > start && a[j] >= a[key]) 
			j--;
		if (i > j) 
			swap(&a[key], &a[j]);
		else 
			swap(&a[i], &a[j]);
	}
	// 엇갈릴 때 부분적 재귀적으로 호출
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

	//오름차순 정렬
	quick_sort(arr, 0, 8);
	for (int i = 0; i < 9; ++i) {
		if (arr[i] == 0)
			continue;
		printf("%d\n", arr[i]);
	}

	return 0;
}