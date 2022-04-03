#include <iostream>
#include <vector>
#define LL long long

using namespace std;

LL solution(int n, int* arr) {
	LL answer = 0;
	vector<LL> dp(n + 1, 0); // dp테이블 초기화

	for (int i = 0; i < n; ++i) {
		dp[i] = arr[i];
		for (int j = i - 1; j >= 0; --j) {
			// 크다면
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		// 교체
		if (answer < dp[i])
			answer = dp[i];
	}

	return answer;
}

int main(void) {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	LL ret = solution(n, arr);
	cout << ret;
	delete[] arr;
	return 0;
}
