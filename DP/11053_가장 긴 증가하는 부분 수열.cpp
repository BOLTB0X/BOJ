#include <iostream>

using namespace std;

// 최대값 비교
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n, int *arr) {
	int answer = -1; // 최대를 위한
	// 메모제이션 생성 및 초기화
	// dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
	int* dp = new int[n];
	for (int i = 0; i < n; ++i) 
		dp[i] = 0;

	// LIS
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; --j) {
			if (arr[i] > arr[j])
				dp[i] = Max(dp[i], dp[j] + 1);
		}
		// 교체
		answer = Max(dp[i], answer);
	}
	
	//메모리 해제
	delete[] dp;
	return answer;
}

int main(void) {
	int n;
	cin >> n;

	//동적할당
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	
	int ret = solution(n, arr);
	cout << ret;
	//메모리 해제
	delete[] arr;
	return 0;
}
