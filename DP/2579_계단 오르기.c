#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int step[301] = { 0, };
int dp[301] = { 0, };

//최대 비교
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
	
	//각 계단오르는 수 메모이제이션에 저장
	dp[0] = step[0];
	dp[1] = max(step[0], step[0] + step[1]);
	dp[2] = max(step[1] + step[2], step[0] + step[2]);
	
	//한칸인 경우와 두칸 건너뛴 경우 중 큰값으로
	for (int i = 3; i < n; ++i) 
		dp[i] = max(step[i] + dp[i - 2], step[i] + step[i - 1] + dp[i - 3]);
	
	printf("%d\n", dp[n-1]);

	return 0;
}
