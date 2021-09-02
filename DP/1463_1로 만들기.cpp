#include <iostream>
using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x;
	int dp[1000001] = { 0 };
	cin >> x;

	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[x] << '\n';
	return 0;
}