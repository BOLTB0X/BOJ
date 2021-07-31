#include <iostream>
using namespace std;

int n, m;
int dp[301] = { 0, };

int solution() {
	cin >> n >> m;
	dp[0] = n - 1;

	for (int i = 1; i < m; i++) {
		dp[i] = dp[i - 1] + n;
	}

	return dp[m - 1];
}

int main(void) {
	cout << solution() << '\n';
	return 0;
}