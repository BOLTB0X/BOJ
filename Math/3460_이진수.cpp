#include <iostream>

using namespace std;

void solution(int n) {
	string binary_number = "";

	while (n > 0) {
		int r = n % 2;
		binary_number += ((char)r + '0');
		n /= 2;
	}

	int size = binary_number.length(); // ±æÀÌ
	for (int i = 0; i <= size; ++i) {
		if (binary_number[i] == '1')
			cout << i << ' ';
	}
	cout << '\n';

	return;
}

int main(void) {
	int T, n;

	cin >> T;

	while (T--) {
		cin >> n;
		solution(n);
	}
	return 0;
}