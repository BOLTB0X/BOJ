#include <iostream>
using namespace std;


// 앞서 계산된 결과를 저장하기 위한 DP 테이블
int Zero_dp[41] = { 1 }, One_dp[41] = {0,1};

void fibonacci(int n) {
// 3=> 2 1 ==> (0과 1을 리턴) , (1을 리턴) = 1 2
// 2=> 1,0 (0과 1을 리턴) = 1 1

// 4=> 3 2               = 2 2

// 0 ==> 1 0
// 1 ==> 0 1
// 2 ==> 1 1
// 3 ==> 1 2
	for (int n = 2; n <= 40; n++) {
		Zero_dp[n] = Zero_dp[n - 1] + Zero_dp[n - 2];
		One_dp[n] = One_dp[n - 1] + One_dp[n - 2];
	}
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n;
		cin >> n;
	
		fibonacci(n);
		cout << Zero_dp[n] << ' ' << One_dp[n] << endl;
	}
	return 0;
}
