#include <iostream>
using namespace std;

int n;
int dp[1001] = { 0, };
int T[1001] = {0, };
int P[1001] = {0, };

int max(int value1, int value2) {
	return value1 > value2 ? value1 : value2;
}

int solution() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> T[i] >> P[i];
	}
	
	dp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		int next = i + T[i];

		if (next > n)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[i+1],dp[next]+P[i]);
	}
	return dp[0];
}

int main(void) {
	cout << solution() << endl;
	return 0;
}
