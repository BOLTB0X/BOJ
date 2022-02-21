#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ML 100001

long long dp[ML][4];
const int INF = 1e9 + 9;

void init(void) {
	for (int i = 0; i < ML; ++i) {
		for (int j = 0; j < 4; ++j)
			dp[i][j] = 0;
	}
	
	//1���� ����� ���� ������ ���
	//n X 4(1,2,3)���� �� ���ڰ� ��� ����ߴ��� üũ
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	//���Ҿ� ���
	for (int i = 4; i < ML; ++i) {
		if (i - 1 >= 0) //1�� ���� ��� X
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % INF;
		if (i - 2 >= 0) //2�� ���� ��� X
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % INF;
		if (i - 3 >= 0) //1�� ���� ��� X
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % INF;
	}
	return;
}

void solution(int T) {
	int n;
	//�ʱ�ȭ
	init();

	while (T--) {
		scanf("%d", &n);
		printf("%lld\n", (dp[n][1] + dp[n][2] + dp[n][3]) % INF);
	}
	return;
}

int main(void) {
	int T;
	scanf("%d", &T);
	solution(T);

	return 0;
}