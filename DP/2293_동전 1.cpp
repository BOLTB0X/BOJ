#include <iostream>
#include <vector>

using namespace std;

//최소
int min(int a, int b) {
	return a < b ? a : b;
}

//메모이제이션
void memoization(vector<int>& coins, int n, int m) {
	//dp테이블 생성 및 초기화
	int* dp = new int[m+1];
	for (int i = 0; i <= m; ++i)
		dp[i] = 0;
	
	//보텀업
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = coins[i]; j <= m; ++j) {
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}

	cout << dp[m] << '\n';

	//메모리 해제
	delete[] dp;
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	//동전의 가치를 담는 벡터
	vector<int> coins(n+1,0);

	for (int i = 1; i <= n; ++i) {
		int value;
		cin >> value;
		coins[i]=value;
	}
	memoization(coins, n, m);
	return 0;
}