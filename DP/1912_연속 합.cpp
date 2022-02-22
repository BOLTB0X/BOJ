#include <iostream>
#include <vector>

using namespace std;

int MAX(int a, int b) {
	return a > b ? a : b;
}

void solution(int n, vector<int>& arr) {
	int answer = 0;
	vector<int> dp(n, 0);
	dp[0] = answer = arr[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = MAX(arr[i] + dp[i - 1], arr[i]);
		answer = MAX(answer, dp[i]);
	}

	cout << answer;
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<int> arr;

	cin >> n;
	arr.resize(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	solution(n, arr);
	return 0;
}
