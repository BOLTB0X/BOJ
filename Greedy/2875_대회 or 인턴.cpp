#include <iostream>

using namespace std;

int solution(int n, int m, int k) {
	int answer = 0;

	while (1) {
		// 여 2 이상 남 1 이상 참가 인원은 최소 3이므로
		if (n < 2 || m < 1 || n + m - 3 < k)
			break;
		n -= 2;
		m--;
		answer++;
	}

	return answer;
}

int main(void) {
	int n, m, k;

	cin >> n >> m >> k;

	int ret = solution(n, m, k);
	cout << ret;

	return 0;
}
