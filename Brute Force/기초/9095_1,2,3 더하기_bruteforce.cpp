#include <iostream>

using namespace std;

int result = 0;

void DFS(int n, int tot) {
	// 초과
	if (tot > n)
		return;

	// 카운트
	if (tot == n) {
		result++;
		return;
	}

	for (int i = 1; i <= 3; ++i) 
		DFS(n, tot + i);
	return;
}

int solution(int n) {
	int answer = 0;

	result = 0; // 초기화
	DFS(n, 0);

	answer = result;
	return answer;
}

int main(void) {
	int T;

	cin >> T;
	while (T--) {
		int n;

		cin >> n;
		int ret = solution(n);
		cout << ret << '\n';
	}
	return 0;
}
