#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MLN 1000001

long long dp[MLN];
long long tot_div[MLN];

void init(void) {
	memset(dp, 0, sizeof(long long) * MLN);
	for (long long i = 1; i < MLN; ++i)
		tot_div[i] = 1;

	for (long long i = 2; i < MLN; ++i) {
		for (long long j = 1; j * i < MLN; ++j)
			tot_div[i * j] += i;
	}

	for (long long i = 1; i < MLN; ++i)
		dp[i] = tot_div[i] + dp[i - 1];

	return;
}

void solution(int T) {
	long long n;
	init();

	while (T--) {
		scanf("%lld", &n);
		printf("%lld\n", dp[n]);
	}

	return;
}

int main(void) {
	int T;

	scanf("%d", &T);

	solution(T);
	return 0;
}
