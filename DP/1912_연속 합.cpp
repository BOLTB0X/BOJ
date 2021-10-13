#include <iostream>

using namespace std;

//�ִ�
int max(int a, int b) {
	return a > b ? a : b;
}

//�ذ�
void solution(void) {
	int n;
	cin >> n;

	//�����Ҵ�
	int* arr = new int[n+1];
	int* dp = new int[n+1];
	dp[0] = arr[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		dp[i] = 0;
	}
	
	//���Ҿ�
	dp[1] = arr[1];
	for (int i = 2; i <= n; ++i) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
	}

	//dp�迭���� �ִ� ã��
	int max_value = dp[1];
	for (int i = 2; i <= n; ++i) {
		if (max_value < dp[i])
			max_value = dp[i];
	}
	cout << max_value << '\n';
	
	//�޸� ����
	delete[] arr;
	delete[] dp;
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