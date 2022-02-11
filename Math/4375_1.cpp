#include <iostream>

using namespace std;

int solution(int n) {
	int mul = 1;
	int	k = 1;

	//x mod N = (x mod N) mod N  이용
	//안그러면 계속 커져 시간초과
	while (1) {
		if (mul % n == 0)
			break;
		else {
			k++;
			mul = mul * 10 + 1;
			mul %= n;
		}
	}
	
	return k;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	while (cin >> n) {
		k = solution(n);
		cout << k << '\n';
	}

	return 0;
}