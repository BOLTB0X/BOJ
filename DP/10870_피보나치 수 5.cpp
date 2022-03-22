#include <iostream>

using namespace std;

long long dp[101];

long long fibonacci(int n) {
	// Å»Ãâ Á¶°Ç
	if (n == 1 || n == 2)
		return 1;
	
	if (dp[n] != 0)
		return dp[n];
	dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return dp[n];
}

int main(void) {
	int n;

	cin >> n;
	if (n == 0)
		cout << '0';
	else {
		long long ret = fibonacci(n);
		cout << ret;
	}
	return 0;
}