#include <iostream>
#define LL long long

using namespace std;

LL solution(LL n) {
	LL answer = 0;
	LL tot = 0; // 합
	LL max_number = 0, plus_number = 1;

	while (1) {
		tot += plus_number;
		max_number++;

		if (tot > n) {
			max_number--;
			break;
		}
		plus_number++;
	}

	answer = max_number;
	return answer;
}

int main(void) {
	LL n;
	
	cin >> n;

	LL ret = solution(n);
	cout << ret;
	return 0;
}
