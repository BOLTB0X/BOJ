#include <iostream>
#include <algorithm>
using namespace std;

int num[4] = { 25,10,5,1 };

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int c;
		cin >> c;
		int rest[4] = { 0, };
		for (int j = 0; j < 4; j++) {
			rest[j] += (c / num[j]);
			c -= (rest[j] * num[j]);
		}
		cout << rest[0] << ' ' << rest[1] << ' ' << rest[2] << ' ' << rest[3] << endl;
	}
	return 0;
}