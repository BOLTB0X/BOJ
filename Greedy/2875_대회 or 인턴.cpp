#include <iostream>

using namespace std;

int solution(int n, int m, int k) {
	int answer = 0;

	while (1) {
		// �� 2 �̻� �� 1 �̻� ���� �ο��� �ּ� 3�̹Ƿ�
		if (n < 2 || m < 1 || (n + m) - 3 < k)
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