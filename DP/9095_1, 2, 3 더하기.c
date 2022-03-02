#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[12];

void init(void) {
	//초기화
	for (int i = 0; i <= 12; ++i) 
		dp[i] = 0;

	dp[1] = 1; // 1
	dp[2] = 2; // 1, 2
	dp[3] = 4; // 1+1+1,1+2,2+1,3

	//보텀업
	for (int i = 4; i <= 12; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	return;
}

int main(void) {
	int T;
	scanf("%d", &T);

	init(); //dp테이블 초기화	
	while (T--) {
		int n;
		scanf("%d", &n);

		//출력
		printf("%d\n", dp[n]);
	}
	return 0;
}
