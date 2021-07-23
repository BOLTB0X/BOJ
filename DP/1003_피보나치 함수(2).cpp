#include <iostream>
using namespace std;

// 3=> 2 1 ==> (0과 1을 리턴) , (1을 리턴) = 1 2
// 2=> 1,0 (0과 1을 리턴) = 1 1

// 4=> 3 2               = 2 2

// 0 ==> 1 0
// 1 ==> 0 1
// 2 ==> 1 1
// 3 ==> 1 2
// 4 ==> 2 2 => F[n-1] F[n] n이 1이상 부터
int F[41] = { 0,1 }; // 초기화

void fibonacci(int n) {
	for (int i = 2; i <= n; i++)
		F[i] = F[i - 1] + F[i - 2];
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		if (n == 0) {
			cout << 1 << ' ' << 0 << endl;
		}
		else {
			fibonacci(n);
			cout << F[n - 1] << ' ' << F[n] << endl;
		}
	}
	return 0;
}