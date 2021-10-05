#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string word;
	int num = 0;
	cin >> word;

	for(int i = 0; i < word.length(); ++i) {
		num *= 16;

		if (word[i] >= 'A' && word[i] <= 'F') {
			num += word[i] - 'A' + 10;
		}
		else {
			num += word[i] - '0';
		}
	}
	cout << num << '\n';
	return 0;
}