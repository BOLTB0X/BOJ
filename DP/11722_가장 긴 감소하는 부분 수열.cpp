#include <iostream>

using namespace std;

int result = -1;

//최대 비교
int max(int a, int b) {
	return a > b ? a : b;
}

void solution(int n, int* arr) {
	//메모제이션 생성 및 초기화
	//dp[i] = i번째 원소를 마지막으로 하는 LDS의 길이
	int* dp = new int[n];
	for (int i = 0; i < n; ++i) {
		dp[i] = 0;
	}

	//분할정복
	for (int i = 0; i < n; ++i) {
		//매 초기화
		int point = 0;
		for (int j = 0; j < i; ++j) {
			//감소한다면
			if (arr[i] < arr[j]) 
				point = max(point, dp[j]);
		}
		dp[i] = point + 1;
		result = max(result, dp[i]);
	}

	cout << result << '\n';
	//메모리 해제
	delete[] dp;
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	//동적할당
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	
	solution(n, arr);
	//메모리 해제
	delete[] arr;
	return 0;
}
