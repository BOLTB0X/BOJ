#include <iostream>

using namespace std;

// 최대공약수
int gcd(int a, int b) {
	// b가 클 경우
	if (a < b)
		swap(a, b);

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

int main(void) {
	int a, b;

	cin >> a >> b;
	cout << gcd(a, b) << '\n' << lcm(a, b);
	return 0;
}
