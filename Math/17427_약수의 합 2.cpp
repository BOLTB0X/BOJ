#include <iostream>
#define LL long long

using namespace std;

LL solution(LL n) {
	LL answer = 0;

	/* // 시간초과
	for (LL i = 1; i <= n; ++i) {
		for (LL j = 1; j <= i; ++j) {
			if (i % j == 0)
				answer += j;
		}
	}
	*/

	// n == 10
	// f(1) = tot(1)
	// f(2) = tot(1, 2) 
	// f(3) = tot(1, 3) 
	// f(4) = tot(1, 2, 4) 
	// f(5) = tot(1, 5)
	// f(6) = tot(1, 2, 3, 6)
	// f(7) = tot(1, 7)
	// f(8) = tot(1, 2, 4, 8)
	// f(9) = tot(1, 3, 9)
	// f(10) = tot(1, 2, 5, 10)

	// 1 -> 4, 2 - > 2, 3 -> 1, 4 -> 1
	// 1은 4번, 2는 2번 3은 1번 4은 1번
 	for (LL i = 1; i <= n; ++i)
		answer += (n / i) * i;
	
	return answer;
}

int main(void) {
	LL n;
	cin >> n;

	LL ret = solution(n);
	cout << ret;

	return 0;
}
