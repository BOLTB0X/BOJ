#include <iostream>

using namespace std;

int dp[100001];

int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n, int* arr) {
	int answer = 0;

	// 초기화
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;

	answer = dp[1] = arr[1];
	for (int i = 2; i <= n; ++i) {
		dp[i] = Max(dp[i - 1] + arr[i], arr[i]);
		answer = Max(answer, dp[i]);
	}

	return answer;
}

int main(void) {
	int n;
	cin >> n;
	
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	int ret = solution(n, arr);
	cout << ret;

	delete[] arr;
	return 0;
}
