#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[1001];
int cards[1001];

//최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer;

	//dp 테이블 초기화
	for (int i = 1; i <= n; ++i)
		dp[i] = 0;

	//보텀업
	for (int i = 1; i <= n; ++i) {
		////즉 i갯수 만큼 살때 조합에의한 값 중 최댓값을 dp테이블에 넣어두면 됌
		for (int j = 1; j <= i; ++j) 
			dp[i] = Max(dp[i - j] + cards[j], dp[i]);
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

	printf("%d",ret);

	return 0;
}
