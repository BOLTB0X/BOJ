#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[1001];
int cards[1001];

int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer;
	//dp테이블 초기화
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;

	//카드 선택갯수 1부터 n까지
	for (int i = 1; i <= n; ++i) {
		//차례로 해당 j를 i만큼 산것과 다른 것과 조합해서
		//산 것중 최댓값 셋팅
		for (int j = 1; j <= i; ++j) {
			dp[i] = MAX(dp[i - j] + cards[j], dp[i]);
		}
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