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

	//최대길이 체크
	for (int i = 0; i < n; ++i) {
		dp[i] = 1; //길이 1로 셋팅
		for (int j = i - 1; j >= 0; --j) {
			if (arr[i] < arr[j]) //작다면
				dp[i] = MAX(dp[i], dp[j] + 1); //업데이트
		}

		answer = MAX(dp[i], answer);
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
