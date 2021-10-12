#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//최소
int min(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	int n;
	scanf("%d", &n);

	//동적할당 및 초기화
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; ++i) {
		dp[i] = 0;
	}
	
	//보턴업
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		//2와 3 동시에 나누어 떨어지는 경우도 존재
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	printf("%d\n", dp[n]);
	free(dp);
	return 0;
}