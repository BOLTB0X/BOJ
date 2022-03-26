#include <iostream>

using namespace std;

// �ִ�����
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

// �ּҰ����
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int solution(int M, int N, int x, int y) {
	int answer = 0;
	int flag = 0; // üũ ��
	int last_year = lcm(M, N); // M�� N�� �ּ� ������� ������

	for (int i = x; i <= last_year; i += M) {
		int tmp = (i % N == 0) ? N : i % N;
		if (tmp == y) {
			answer = i;
			flag = 1;
			break;
		}
	}

	// ���ü� ���ٸ�
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