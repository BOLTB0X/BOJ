#include <iostream>

using namespace std;

// 최대공약수
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

// 최소공배수
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int solution(int M, int N, int x, int y) {
	int answer = 0;
	int flag = 0; // 체크 용
	int last_year = lcm(M, N); // M과 N의 최소 공배수가 마지막

	for (int i = x; i <= last_year; i += M) {
		int tmp = (i % N == 0) ? N : i % N;
		if (tmp == y) {
			answer = i;
			flag = 1;
			break;
		}
	}

	// 나올수 없다면
	if (flag == 0)
		answer = -1;

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, M, N, x, y;

	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;

		int ret = solution(M, N, x, y);
		cout << ret << '\n';
	}

	return 0;
}