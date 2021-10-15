#include <iostream>

using namespace std;

//최댓값 비교
int max(int a, int b) {
	return a > b ? a : b;
}

void solution(void) {
	int n;
	cin >> n;

	//동적할당
	int* arr = new int[n];
	int* dp = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dp[i] = 0;
	}
	//보텀업
	int max_value = dp[0] = arr[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = max(arr[i], dp[i-1] + arr[i]);
		//최댓값 찾기
		if (max_value < dp[i])
			max_value = dp[i];
	}
	//정답 출력
	cout << max_value << '\n';

	//메모리 해제
	delete[] dp;
	delete[] arr;
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
