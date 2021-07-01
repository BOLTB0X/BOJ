#include <iostream>
using namespace std;

int main() {
	int n;
	int i = 1, answer = 0;
	cin >> n;
	while (i<=n) {
		answer += (n - i + 1);
		i *= 10;
	}
	cout << answer << '\n';
	return 0;
}