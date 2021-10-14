#include <iostream>
#include <string>

using namespace std;

string trans(int n, int b) {
	string tmp = "";
	string s = "";

	while (n>=1) {
		int r = n % b;
		if (r >= 10)
			tmp += (char)(r + 'A' - 10);
		else
			tmp += (char)(r + '0');

		n /= b;
	}
	for (int i = tmp.length() - 1; i >= 0; i--) 
		s += tmp[i];
	return s;
}

int main(void) {
	int N, B;
	cin >> N >> B;

	string st = trans(N, B);
	cout << st << '\n';
	return 0;
}
