#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool is_decimal(char c) {
	if (c >= '1' && c <= '9') {
		return true;
	}
	return false;
}

bool is_hexadecimal(char c) {
	if (c == 'x') {
		return true;
	}
	return false;
}

int main() {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string X;
	cin >> X;
	//10진수
	if (is_decimal(X[0])) {

		cout << X << '\n';
		return 0;
	}
	
	//16진수
	else if (is_hexadecimal(X[1])) {
		X.erase(0, 2);
		int tot = 0;
		for (int i = X.size() - 1; i >= 0; i--) {
			if (X[i] <= '9')
				tot += ((X[i] - '0') * pow(16, X.size() - 1 - i));
			else
				tot += ((X[i] - 'a' + 10) * pow(16, X.size() - 1 - i));
		}
		cout << tot << '\n';
		return 0;
	}
	//8진수
	else {
		int tot = 0;
		X.erase(0, 1);
		for (int i = X.size() - 1; i >= 0; i--) {
			tot += ((X[i] - '0') * pow(8, X.size() - 1 - i));
		}
		cout << tot << '\n';
		return 0;
	}
}