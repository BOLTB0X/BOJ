#include <iostream>
#define LL long long

using namespace std;

int solution(int n) {
	LL cnt = 1;
	LL	k = 1;

	// 1�θ� �̷���� n�� ����� ã�� -> 1, 11, 111, .....
	// x mod N = (x mod N) mod N  �̿�
	while (1) {
		// k�� n�� ������������ -> ���
		if (k % n == 0)
			break;

		// 11 = 9 + 2 = 2 (mod 3)
		k %= n;
		k = k * 10 + 1;
		cnt++;
	}
	
	return cnt;
}

int main(void) {
	int n;

	while (cin >> n) {
		LL ret = solution(n);
		cout << ret << '\n';
	}

	return 0;
}