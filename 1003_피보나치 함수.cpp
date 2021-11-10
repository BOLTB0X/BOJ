#include <iostream>

using namespace std;

int dp[41] = { 0, };

void fibonacci(int n) {
	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	return;
}

void solution(void) {
	int T;
	dp[0] = 0;
	dp[1] = 1;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		if (n == 0)
			cout << 1 << ' ' << 0 << '\n';
		else {
			fibonacci(n);
			cout << dp[n - 1] << ' ' << dp[n] << '\n';
		}
	}

	return;
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}