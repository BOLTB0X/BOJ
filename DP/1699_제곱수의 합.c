#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[100001] = { 0, };

//최솟값반환
int MIN(int a, int b) {
	return a < b ? a : b;
}

int solution(int n) {
	int answer = 0;

	//1, 1 1, 1 1 1,....
	for (int i = 0; i <= n; ++i)
		dp[i] = i;
	// n = 2 -> 2 (1 1)
	// n = 3 -> 3 (1 1 1)
	// n = 4 -> 1 (2)
	// n = 5 -> 2 (2 1)
	// n = 6 -> 3 (1 1 2)
	for (int i = 2; i <= n; ++i) {
		//i가 4부터 진짜 시작
		//보텀업 방식
		for (int j = 2; j * j <= i; ++j) {
			dp[i] = MIN(dp[i], dp[i - j * j] + 1);
		}
	}

	answer = dp[n];
	return answer;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int ret = solution(n);
	printf("%d", ret);
	return 0;
}