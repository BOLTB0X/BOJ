#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000001

long long div_tot[MAX_LEN];
long long dp[MAX_LEN];

void set_div(void) {
	memset(dp, 0, sizeof(long long) * MAX_LEN);

	for (long long i = 0; i < MAX_LEN; ++i)
		div_tot[i] = 1;
	
	for (long long i = 2; i < MAX_LEN; ++i) {
		for (long long j = 1; j*i< MAX_LEN; ++j)
			div_tot[i * j] += i;
	}

	for (long long i = 1; i < MAX_LEN; ++i)
		dp[i] = div_tot[i] + dp[i - 1];
	
	return;
}

void solution(int T) {
	long long n;
	set_div();

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