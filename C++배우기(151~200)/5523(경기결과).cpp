#include <iostream>
using namespace std;

int T;
int a_cnt, b_cnt;

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) a_cnt += 1;
		else if (a < b) b_cnt += 1;
	}
	cout << a_cnt << " " << b_cnt << endl;
	return 0;
}