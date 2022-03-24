#include <iostream>

using namespace std;

long long solution(long long S) {
	long long answer = 0;
	long long tot = 0, max_number = 0, plus_number = 1;

	while (1) {
		tot += plus_number;
		max_number++;

		// 커진다면
		if (tot > S) {
			max_number--;
			break;
		}

		plus_number++; // 더해지는 수 증가
	}
	answer = max_number;
	return answer;
}

int main(void) {
	long long S;

	cin >> S;
	long long ret = solution(S);
	cout << ret;

	return 0;
}
