#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);

		//입력 받은 n만큼 배열 생성
		int* dp = malloc(sizeof(int) * (n + 1));

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++) {
			dp[i] = 0;
		}
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}