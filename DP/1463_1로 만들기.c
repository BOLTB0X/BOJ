#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//최솟값 반환
int MIN(int a, int b) {
	return a < b ? a : b;
}

int solution(int n) {
	int answer = 0;
	//동적할당
	int* dp = malloc(sizeof(int) * (n + 1));
	//초기화
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;

	//2부터 보텀업
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;

		//2와 3으로 나누어 떨어지는 경우 체크
		if (i % 2 == 0)
			dp[i] = MIN(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) //나누어 떨어지는 경우
			dp[i] = MIN(dp[i], dp[i / 3] + 1);
	}

	answer = dp[n];
	free(dp);
	return answer;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int ret = solution(n);
	printf("%d", ret);
	return 0;
}
