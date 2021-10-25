#include <iostream>

using namespace std;

//최댓값
int max(int a, int b) {
	return a > b ? a : b;
}

void solution(void) {
	int n;
	cin >> n;
	
	//동적할당
	int* steps = new int[n + 1];
	int* dp = new int[n + 1];

	//입력
	for (int i = 1; i <= n; ++i) {
		cin >> steps[i];
	}

	//메모이제이션
	dp[1] = steps[1];
	dp[2] = max(steps[1], steps[1] + steps[2]);
	dp[3] = max(steps[2] + steps[3], steps[1] + steps[3]);
	
	for (int i = 4; i <= n; ++i)
		//한칸 건너뛰기 + 연속
		dp[i] = max(steps[i] + dp[i - 2], steps[i] + steps[i - 1] + dp[i - 3]);
	
	//출력
	cout << dp[n] << '\n';

	//메모리해제
	delete[] dp;
	delete[] steps;

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