#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LL long long

LL solution(int n) {
	LL answer = 0;
	LL* dp = malloc(sizeof(LL) * (n + 1));
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	answer = dp[n];
	free(dp);
	return answer;
}

int main(void) {
	int n;
	scanf("%d", &n);

	LL ret = solution(n);
	printf("%lld", ret);

	return 0;
}
