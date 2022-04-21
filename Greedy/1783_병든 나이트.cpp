#include <iostream>

using namespace std;

int Min(int a, int b) {
	return a < b ? a : b;
}

int solution(int n, int m) {
	int answer = 0;

	// 이동 불가
	if (n == 1)
		answer = 1; // 시작하는 칸도 포함

	// 2, 3 이동 가능
	else if (n == 2)
		answer = Min(4, (m + 1) / 2);

	// 1, 2, 3, 4
	else if (n >= 3) {

		if (m <= 6)
			answer = Min(4, m);
		else
			answer = m - 2;
	}

	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	int ret = solution(n, m);
	cout << ret;
	return 0;
}