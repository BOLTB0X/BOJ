#include <iostream>
#include <vector>

using namespace std;

//최솟값반환
int MIN(int a, int b) {
	return a < b ? a : b;
}

void solution(int n) {
	int answer = 0;
	vector<int> dp(n + 1, 0);

	// 1, 1 + 1, 1 + 1 + 1...식으로 초기값 셋팅
	for (int i = 0; i <= n; ++i)
		dp[i] = i;
	
	//보텀업 방식
	for (int i = 2; i <= n; ++i) {
		//기존 dp테이블 값과 기존 i에 제곱값을 뺀 dp테이블 + 1 중 최솟값 반환
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
