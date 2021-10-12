#include <iostream>

using namespace std;

//�ִ�
int max(int a, int b) {
	return a > b ? a : b;
}

void solution(void) {
	int n, result = -1;
	cin >> n;

	//�����Ҵ� �� �ʱ�ȭ
	int* arr = new int[n + 1];
	int* dp = new int[n + 1];
	//dp[i] = i��° ���Ҹ� ���������� �ϴ� LIS�� ����
	for (int i = 0; i <= n; ++i) {
		dp[i] = 0;
		arr[i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		int point = 0;
		//�κм��� �� ���� �� �κ� ������ ã�ƾ���
		for (int j = 1; j < i; ++j) {
			//���� �����Ѵٸ�
			if (arr[i] > arr[j])
				point = max(point, dp[j]);
		}
		dp[i] = point + 1;
		result = max(result, dp[i]);
	}
	cout << result << '\n';
	delete[] arr;
	delete[] dp;
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//�ذ�
	solution();
	return 0;
}