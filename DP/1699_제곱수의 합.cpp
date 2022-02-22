#include <iostream>
#include <vector>

using namespace std;

int MIN(int a, int b) {
	return a < b ? a : b;
}

void solution(int n) {
	int answer = 0;
	vector<int> dp(n + 1, 0);

	// 1, 1 + 1, 1 + 1 + 1...식으로 초기값 셋팅
	for (int i = 0; i <= n; ++i)
		dp[i] = i;
	
	//보텀업방식
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j * j <= i; ++j) {
			dp[i] = MIN(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	solution(n);
	return 0;
}
