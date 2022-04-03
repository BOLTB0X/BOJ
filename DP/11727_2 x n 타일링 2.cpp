#include <iostream>
#define LL long long
#define Mod 10007

using namespace std;

LL solution(int n) {
	LL answer = 0;

	LL* dp = new LL[n + 1];
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;

	dp[1] = 1;
	dp[2] = 3;

	// º¸ÅÒ¾÷
	for (int i = 3; i <= n; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % Mod;

	answer = dp[n];
	delete[] dp;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	LL ret = solution(n);
	cout << ret;
	return 0;
}