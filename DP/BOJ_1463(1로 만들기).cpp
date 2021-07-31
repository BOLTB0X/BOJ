#include <iostream>
using namespace std;

int dp[1000001] = { 0, };
int n;

int min(int value1, int value2) {
	return value1 < value2 ? value1 : value2;
}
int solution(void) {
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	return dp[n];
}

int main(void) {
	cout << solution() << '\n';
	return 0;
}
