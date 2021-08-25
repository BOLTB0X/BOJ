#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main(void) {
	int n;
	long long dp[91];
	dp[0] = 0;
	dp[1] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	long long answer = dp[n];
	printf("%lld\n", answer);
	return 0;
}