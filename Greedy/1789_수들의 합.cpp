#include <iostream>

using namespace std;

long long solution(long long S) {
	long long answer = 0;
	long long max_number = 0, number = 1, tot = 0;

	while (1) {
		tot += number;
		max_number++;

		if (tot > S) {
			max_number--;
			break;
		}
		number++;
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
