#include <iostream>

using namespace std;

void solution(void) {
	int n;
	cin >> n;

	int d = 2;
	while (n != 1) {
		if (n % d == 0) {
			n /= d;
			cout << d << '\n';
		}
		else
			d++;
	}

	return;
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}