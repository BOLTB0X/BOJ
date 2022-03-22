#include <iostream>

using namespace std;

int main(void) {
	int n, k;
	int idx = 0;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			idx++;

			if (idx == k) {
				cout << i;
				return 0;
			}
		}
	}

	// 없으므로
	cout << '0';
	return 0;
}