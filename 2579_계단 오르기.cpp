#include <iostream>

using namespace std;

//�ִ�
int max(int a, int b) {
	return a > b ? a : b;
}

void solution(void) {
	int n;
	cin >> n;
	
	//�����Ҵ�
	int* steps = new int[n + 1];
	int* dp = new int[n + 1];

	//�Է�
	for (int i = 1; i <= n; ++i) {
		cin >> steps[i];
	}

	//�޸������̼�
	dp[1] = steps[1];
	dp[2] = max(steps[1], steps[1] + steps[2]);
	dp[3] = max(steps[2] + steps[3], steps[1] + steps[3]);
	
	for (int i = 4; i <= n; ++i)
		//��ĭ �ǳʶٱ� + ����
		dp[i] = max(steps[i] + dp[i - 2], steps[i] + steps[i - 1] + dp[i - 3]);
	
	//���
	cout << dp[n] << '\n';

	//�޸�����
	delete[] dp;
	delete[] steps;

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