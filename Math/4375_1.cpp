#include <iostream>
#define LL long long

using namespace std;

int solution(int n) {
	LL cnt = 1;
	LL	k = 1;

	// 1로만 이루어진 n의 배수를 찾는 -> 1, 11, 111, .....
	// x mod N = (x mod N) mod N  이용
	while (1) {
		// k가 n에 나눠떨어지면 -> 배수
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