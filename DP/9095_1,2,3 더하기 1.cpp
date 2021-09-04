#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		int dp[12] = { 0, };
		cin >> n;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		//╨╦ер╬В
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << '\n';
	}
	return 0;
}
