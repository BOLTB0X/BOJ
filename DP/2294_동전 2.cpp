#include <iostream>

using namespace std;

int coins[101]; // 동전

// 최솟값반환
int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n, int k) {
	int answer = 0;

	// 동적할당 및 초기화
	int* dp = new int[k + 1];
	for (int i = 1; i <= k; ++i)
		dp[i] = 10001; // 최댓값

	dp[0] = 0;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			int coin = coins[j]; // 사용할 동전
			if (i - coin >= 0) // 거슬러 줄 수 있다면
				dp[i] = Min(dp[i], dp[i - coin] + 1);
		}
	}

	answer = dp[k];
	delete[] dp;

	// 불가능하다면
	if (answer == 10001)
		answer = -1;
	return answer;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> coins[i];

	int ret = solution(n, k);
	cout << ret;
	return 0;
}