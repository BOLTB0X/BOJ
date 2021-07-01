#include <iostream>
using namespace std;

int a[10];
int b[10];

int main(void) {
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> b[i];
	}
	
	int a_cnt = 0;
	int b_cnt = 0;

	for (int i = 0; i < 10; i++) {
		if (a[i] < b[i]) b_cnt += 1;
		else if (a[i] > b[i]) a_cnt += 1;
	}
	if (a_cnt > b_cnt) {
		cout << 'A' << '\n';
	}
	else if (a_cnt < b_cnt) {
		cout << 'B' << '\n';
	}
	else cout << 'D' << '\n';
}