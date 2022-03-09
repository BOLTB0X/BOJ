#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ML 100001

int arr[ML];
int dp[ML];

//큰 값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int result;
	for (int i = 0; i < n; ++i) 
		dp[i] = 0;
	
	dp[0] = result = arr[0];

	//보텀업
	for (int i = 1; i < n; ++i) {
		//음수가 있으므로
		dp[i] = Max(arr[i] + dp[i - 1], arr[i]);
		result = Max(dp[i], result);
	}

	return result;
}

int main(void) {
	int n, ret;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	ret = solution(n);
	printf("%d", ret);
	return 0;
}
