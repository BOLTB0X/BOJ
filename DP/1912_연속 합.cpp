#include <iostream>

using namespace std;

// 최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n, int* arr) {
	int answer = 0;

	int* dp = new int[n];
	for (int i = 0; i < n; ++i)
		dp[i] = 0;

	answer = dp[0] = arr[0];
	int tot = arr[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = Max(dp[i - 1] + arr[i], arr[i]);
		answer = Max(dp[i], answer);
	}

	delete[] dp;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret = solution(n, arr);
	cout << ret;
	delete[] arr;
	return 0;
}
