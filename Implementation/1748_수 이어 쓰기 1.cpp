#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int idx = 1;
	int answer = 0;
	while (idx <= n) {
		answer += (n - idx + 1);
		idx *= 10;
	}

	cout << answer << '\n';
	return 0;
}