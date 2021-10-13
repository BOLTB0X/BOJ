#include <iostream>
#include <vector>

using namespace std;

//�ּ�
int min(int a, int b) {
	return a < b ? a : b;
}

//�޸������̼�
void memoization(vector<int>& coins, int n, int m) {
	//dp���̺� ���� �� �ʱ�ȭ
	int* dp = new int[m+1];
	for (int i = 0; i <= m; ++i)
		dp[i] = 0;
	
	//���Ҿ�
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = coins[i]; j <= m; ++j) {
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}

	cout << dp[m] << '\n';

	//�޸� ����
	delete[] dp;
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	//������ ��ġ�� ��� ����
	vector<int> coins(n+1,0);

	for (int i = 1; i <= n; ++i) {
		int value;
		cin >> value;
		coins[i]=value;
	}
	memoization(coins, n, m);
	return 0;
}