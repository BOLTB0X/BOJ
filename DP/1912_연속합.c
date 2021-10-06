#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//최대
int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	//크기 입력
	int n, result;
	scanf("%d", &n);
	//동적할당
	int* arr = malloc(sizeof(int) * (n + 1));
	int* dp = malloc(sizeof(int) * (n + 1));

	//입력
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	//셋팅
	dp[0] = arr[0];
	result = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(result, dp[i]);
	}
	printf("%d\n", result);
	free(arr);
	free(dp);
	return 0;
}