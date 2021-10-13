#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//dp배열 초기화
int dp[10001][4] = { 0, };

//메모리제이션
void memoization(int n, int k) {
	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	//값이 존재 하면
	if (dp[n][k])
		return dp[n][k];

	for (int i = 4; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			int tot = 0;
			if (j == 1) {
				dp[i][j] = 1;
				continue;
			}
			for (int l = 1; l <= j; ++l) {
				tot += dp[i - j][l];
			}
			dp[i][j] = tot;
		}
	}
	return dp[n][k];
}

int main(void) {
	int T;
	scanf("%d", &T);

	//테스트 케이스 시작
	while (T--) {
		int n;
		scanf("%d", &n);
		memoization(n, 3);
		printf("%d\n", dp[n][1] + dp[n][2] + dp[n][3]);
	}
	return 0;
}