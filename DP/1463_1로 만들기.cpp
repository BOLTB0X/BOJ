#include <iostream>

using namespace std;

int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n) {
	int answer = 0;

	//dp 테이블 생성 및 초기화
	int* dp = new int[n + 1];
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;

	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0)
			dp[i] = Min(dp[i / 3] + 1, dp[i]);
		
		if (i % 2 == 0)
			dp[i] = Min(dp[i / 2] + 1, dp[i]);
	}

	answer = dp[n];
	delete[] dp;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	int ret = solution(n);
	cout << ret;
	return 0;
}
