#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		string st;
		int sum1, sum2 = 0;
		cin >> st;

		sum1 = (st[0] - 'A') * 26 * 26 + (st[1] - 'A') * 26 + (st[2] - 'A');
		sum2 += (st[4] - 48) * 1000 + (st[5] - 48) * 100 + (st[6] - 48)*10 + (st[7] - 48);

		if (abs(sum1 - sum2) <= 100) cout << "nice" << endl;
		else cout << "not nice" << endl;
	}

	return 0;
}