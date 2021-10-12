#include <iostream>

using namespace std;

//최대
int max(int a, int b) {
	return a > b ? a : b;
}

void solution(void) {
	int n, result = -1;
	cin >> n;

	//동적할당 및 초기화
	int* arr = new int[n + 1];
	int* dp = new int[n + 1];
	//dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
	for (int i = 0; i <= n; ++i) {
		dp[i] = 0;
		arr[i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		int point = 0;
		//부분수열 중 가장 긴 부분 수열을 찾아야함
		for (int j = 1; j < i; ++j) {
			//만약 증가한다면
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
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//해결
	solution();
	return 0;
}