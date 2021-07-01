#include <iostream>
using namespace std;

int T; //테스트 케이스
int a, b;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << lcm(a, b) << ' ' << gcd(a, b) << '\n';
	}
	return 0;
}