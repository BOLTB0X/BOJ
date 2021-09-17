#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	

int main(void) {
	int n;
	//dp용 배열
	int dp[16] = { 0, };
	//시간저장 배열
	int T[16];
	//급료저장 배열
	int P[16];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d %d", &T[i], &P[i]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			//해당 범위내
			if (j + T[j] - 1 <= i) {
				if (dp[i] < dp[j - 1] + P[j])
					dp[i] = dp[j - 1] + P[j];
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}