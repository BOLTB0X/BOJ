#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[41] = { 0,1 };

void fibonacci(int n) {
	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	return;
}

int main(void) {
	int T;
	scanf("%d", &T);

	while (T--) {
		int n;
		scanf("%d", &n);

		if (n == 0)
			printf("1 0\n");
		else {
			fibonacci(n);
			printf("%d %d\n", dp[n - 1], dp[n]);
		}
	}

	return 0;
}