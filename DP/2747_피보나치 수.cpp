#include <cstdio>
using namespace std;

int main(void) {
	long long dp[45] = { 0, };
	int n;

	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int answer = dp[n];
	printf("%d\n", answer);
	return 0;
}