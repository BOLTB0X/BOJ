#include <iostream>
using namespace std;

int dp[10001][4] = { 0, };

void solution() {
	dp[0][1] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 10000; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		if (i>=3)
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin >> test;
	solution();
	while (test--) {
		int n;
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}
	return 0;
}