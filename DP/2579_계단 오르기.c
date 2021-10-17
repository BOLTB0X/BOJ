#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int step[301] = { 0, };
int dp[301] = { 0, };

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &step[i]);
		dp[i] = 0;
	}

	dp[0] = step[0];
	dp[1] = max(step[0], step[0] + step[1]);
	dp[2] = max(step[1] + step[2], step[0] + step[2]);

	for (int i = 3; i < n; ++i) 
		dp[i] = max(step[i] + dp[i - 2], step[i] + step[i - 1] + dp[i - 3]);
	
	printf("%d\n", dp[n-1]);

	return 0;
}