#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	

int main(void) {
	int n;
	//dp�� �迭
	int dp[16] = { 0, };
	//�ð����� �迭
	int T[16];
	//�޷����� �迭
	int P[16];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d %d", &T[i], &P[i]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			//�ش� ������
			if (j + T[j] - 1 <= i) {
				if (dp[i] < dp[j - 1] + P[j])
					dp[i] = dp[j - 1] + P[j];
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}