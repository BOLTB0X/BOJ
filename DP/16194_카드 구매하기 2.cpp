#include <iostream>

using namespace std;

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n, int* cards) {
	int answer = 0;

	// dp테이블 생성 및 초기화
	int* dp = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		dp[i] = 10001;

	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i - j >= 0)
				dp[i] = Min(dp[i], cards[j] + dp[i - j]);
		}
	}

	answer = dp[n];
	delete[] dp;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	int* cards = new int[n + 1];

	for (int i = 1; i <= n; ++i)
		cin >> cards[i];

	int ret = solution(n, cards);
	cout << ret;

	delete[] cards;
	return 0;
}