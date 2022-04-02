#include <iostream>
#include <vector>
using namespace std;

int coins[101]; // 동전 배열

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n, int k) {
	int answer = -1;
	vector<int> dp(k + 1, 10001); // dp 테이블 생성 및 초기화
	
	// 보텀업 방식
	// 중복허용
	dp[0] = 0;
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			int coin = coins[j];

			if (i >= coin)
				dp[i] = Min(dp[i], dp[i - coin] + 1);
		}
	}

	// 거슬러 주면
	if (dp[k] != 10001)
		answer = dp[k];
	return answer;
}

int main(void) {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> coins[i];

	int ret = solution(n, k);
	cout << ret;

	return 0;
}
