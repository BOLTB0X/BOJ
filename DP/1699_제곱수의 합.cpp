#include <iostream>
#include <vector>

using namespace std;

// 최솟값반환
int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n) {
	int answer = 0;
	
	// dp 테이블 생성 및 초기화
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i)
		dp[i] = i; // 1, 1 1, 1 1 1, 1 1 1 1, ......

	// 보텀업
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j *j<=n; ++j)
			// 표현이 가능하다면
			if (i - j * j >= 0) {
				dp[i] = Min(dp[i], dp[i - j * j] + 1);
			}
	}

	answer = dp[n];
	return answer;
}

int main(void) {
	int n;
	cin >> n;

	int ret = solution(n);
	cout << ret;
	return 0;
}
