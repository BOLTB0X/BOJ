#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);

	//�����Ҵ� �� �ʱ�ȭ
	long long * dp = (long long *)malloc(sizeof(long long) * (n + 1));
	for (int i = 0; i <= n; ++i) {
		dp[i] = 0;
	}
	dp[1] = 1;
	dp[2] = 2;

	//���Ҿ� ���
	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	// 10007�� ���� �������� ���
	printf("%lld\n", dp[n]);
	free(dp);
	return 0;
}