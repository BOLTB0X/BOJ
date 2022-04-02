#include <iostream>
#include <vector>

using namespace std;

int coins[101];

int solution(int n, int k) {
	int answer = 0;
	vector<int> dp(k + 1, 0); // dp 테이블 생성 및 초기화

	// 경우의 수를 알고 싶은 경우
	// 보텀업
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		int coin = coins[i];
		for (int j = coin; j <= k; ++j) 
			dp[j] += dp[j - coin];
	}

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
