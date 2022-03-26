#include <iostream>

using namespace std;

int main(void) {
	int n;
	int idx = 1, answer = 0;

	cin >> n;

	while (idx <= n) {
		answer += (n - idx + 1);
		idx *= 10;
	}
	
	cout << answer << '\n';
	return 0;
}
