#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//최댓값 반환
int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution(int n, int* arr) {
	int answer = 0;
	int* dp = (int*)malloc(sizeof(int) * n);
	//dp 초기화
	for (int i = 0; i < n; ++i)
		dp[i] = 0;

	//분할정복
	for (int i = 0; i < n; ++i) {
		int check = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j])
				check = MAX(check, dp[j]);
		}
		dp[i] = check + 1;
		if (answer < dp[i])
			answer = dp[i];
	}
	return answer;
}

int main(void) {
	int n;
	int* arr;
	
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	int ret = solution(n, arr);
	printf("%d", ret);
	free(arr);
	return 0;
}