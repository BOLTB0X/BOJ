#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int max (int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n, result = -1;
	scanf("%d", &n);
	
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int max_value = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] < arr[i + 1]) {
			max_value += (arr[i + 1] - arr[i]);
		}
		else {
			result = max(result, max_value);
			max_value = 0;
		}
	}
	result = max(result, max_value);
	printf("%d\n", result);

	free(arr);
	return 0;
}