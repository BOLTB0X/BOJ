#include <iostream>

using namespace std;

int coins[101]; // ����

// �ּڰ���ȯ
int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n, int k) {
	int answer = 0;

	// �����Ҵ� �� �ʱ�ȭ
	int* dp = new int[k + 1];
	for (int i = 1; i <= k; ++i)
		dp[i] = 10001; // �ִ�

	dp[0] = 0;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			int coin = coins[j]; // ����� ����
			if (i - coin >= 0) // �Ž��� �� �� �ִٸ�
				dp[i] = Min(dp[i], dp[i - coin] + 1);
		}
	}

	answer = dp[k];
	delete[] dp;

	// �Ұ����ϴٸ�
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