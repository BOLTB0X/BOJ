#include <iostream>
#include <string>

using namespace std;

//dp���̺� �ʱ�ȭ
long long dp[91] = { 0, };

void solution(void) {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;

	//���Ҿ�
	for (int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	
	//���
	cout << dp[n] << '\n';
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}