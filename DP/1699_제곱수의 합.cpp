#include <iostream>
#include <vector>

using namespace std;

//최솟값반환
int Min(int a, int b) {
	return a < b ? a : b;
}

void solution(int n) {
	int answer = 0;
	// 초기화
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i)
		dp[i] = i; // 1, 1 1, 1 1 1, 1 1 1 1,......

	//보텀업 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j * j <= i; ++j) 
			dp[i] = Min(dp[i], dp[i - j * j] + 1);
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
