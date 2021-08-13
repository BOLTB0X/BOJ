#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int sum(int arr[]) {
	int tot = 0;
	for (int i = 0; i < 9; i++) {
		tot += arr[i];
	}
	return tot;
}

void select_sort(int arr[]) {
	for (int i = 0; i < 9; i++) {
		int min_idx = i;
		for (int j = i + 1; j < 9; j++) {
			if (arr[min_idx] > arr[j]) {
				min_idx = j;
			}
		}
		swap(&arr[min_idx], &arr[i]);
	}
}

int main(void) {
	int arr[9];
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum(arr) - arr[i] - arr[j] == 100) {
				arr[i] = 0;
				arr[j] = 0;
				break;
			}
		}
		if (sum(arr) == 100) {
			break;
		}
	}
	select_sort(arr);
	for (int i = 2; i < 9; i++) {
		if (arr[i] == 0) continue;
		printf("%d\n", arr[i]);
	}
	return 0;
}