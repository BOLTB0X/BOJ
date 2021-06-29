#include <iostream>
using namespace std;

int dp[1000000] = { 0, };
int n;

int main(void) {
	cin >> n;
	for (int i=2;i<=n;i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3]+1;
		}
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2]+1;
		}
	}
	cout << dp[n] << '\n';
}