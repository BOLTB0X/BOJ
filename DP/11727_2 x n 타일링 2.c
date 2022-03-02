#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long solution(int n) {
	long long answer = 0;
	
	//동적할당 및 초기화
	long long* dp = (long long*)malloc(sizeof(long long) * (n + 1));
	for (int i = 0; i <= n; ++i) 
		dp[i] = 0;
	
	dp[1] = 1;
	dp[2] = 3;

	//보텀업 방식
	for (int i = 3; i <= n; ++i)
		//점화식 i-2의 *2배 해주고 더해야함
		dp[i] = (dp[i - 1] + (dp[i - 2] * 2)) % 10007;
	
	// 10007로 나눈 나머지를 출력
	answer = dp[n];
	free(dp);
	return answer;
}

int main(void) {
	int n;
	scanf("%d", &n);

	long long ret = solution(n);
	printf("%lld\n", ret);
	return 0;
}
