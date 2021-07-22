#include <iostream>
using namespace std;

// 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
int d[41];

int fibonacci(int n) {
	if (n == 0) {
		d[0] = 0;
		return 0;
	}
	else if (n == 1) {
		d[1] = 1;
		return 1;
	}
	if (d[n] != 0) {
		//계산된 값
		return d[n];
	} 
	else return d[n]= fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n;
		cin >> n;
		if (n == 0) cout << 1 << ' ' << 0 << endl;
		else if (n == 1) cout << 0 << ' ' << 1 << endl;
		else {
			fibonacci(n);
			cout << d[n - 1] << ' ' << d[n] << endl;
		}
	}
	return 0;
}