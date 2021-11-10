#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main(void) {
	int n;
	scanf("%d", &n);

	//동적할당
	long long* dp = malloc(sizeof(long long) * (n + 1));
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	printf("%lld\n", dp[n]);

	//메모리 해제
	free(dp);
	return 0;
}