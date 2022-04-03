#include <iostream>

using namespace std;

int dp[12] = { 0, }; // dp 테이블

void do_dynamic(void) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	// 보텀업
	for (int i = 4; i <= 11; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	return;
}

int main(void) {
	int T, n;
	cin >> T;

	do_dynamic();
	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
