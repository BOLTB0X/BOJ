#include <iostream>

using namespace std;

int dp[100001] = { 0, };

//최솟값
int min(int a, int b) {
	return a < b ? a : b;
}

//초기화
void init(int n) {
	for (int i = 0; i <= n; ++i)
		dp[i] = i;
	return;
}

void solution(void) {
	int n;
	cin >> n;

	//초기화
	init(n);

	for (int i = 2; i <= n; i++)
		for (int j = 2; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);

	cout << dp[n] << '\n';
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