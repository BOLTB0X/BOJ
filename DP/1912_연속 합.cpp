#include <iostream>

using namespace std;

int arr[100000];
int dp[100000] = { 0, };

//최댓값 비교
int max(int a, int b) {
	return a > b ? a : b;
}

void solution(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int max_value = arr[0];
	dp[0] = arr[0];

	//보텀업
	for (int i = 1; i < n; ++i) {
		dp[i] = max(arr[i], arr[i] + dp[i - 1]);

		if (dp[i] > max_value)
			max_value = dp[i];
	}

	cout << max_value << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
