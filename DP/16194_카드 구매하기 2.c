#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[1001] = { 0, };
int cards[1001];

//최솟값
int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n) {
	int answer = 0;

	//최소값을 위한 dp초기화
	for (int i = 1; i <= n; ++i)
		dp[i] = 0x7fffffff;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) 
			dp[i] = Min(dp[i - j] + cards[j], dp[i]);
	}
	
	answer = dp[n];
	return answer;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &cards[i]);

	int ret = solution(n);
	printf("%d", ret);
	return 0;
}