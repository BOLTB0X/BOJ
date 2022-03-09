#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MS 100001 //최대 길이

long long dp[MS][4]; //dp 테이블
const int INF = 1e9 + 9;

void init_dp(void) {
	//dp 테이블 초기화
	for (int i = 0; i < MS; ++i) {
		for (int j = 0; j < 4; ++j)
			dp[i][j] = 0;
	}

	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	//보텀업 방식
	for (int i = 4; i < MS; ++i) {
		if (i - 1 >= 0) //1을 연속 사용 X
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % INF;
		if (i - 2 >= 0) //2을 연속 사용 X
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % INF;
		if (i - 3 >= 0) //3을 연속 사용 X
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % INF;
	}

	return;
}

void solution(int T) {
	int n;
	init_dp();
	//테스트 케이스 시작
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
