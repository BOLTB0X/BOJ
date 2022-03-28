#include <iostream>

using namespace std;

int solution(int E, int S, int M) {
	int year = 1;

	while (1) {
		// 최소공배수 지점이면
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) 
			break;
		year++;
	}

	return year;
}

int main(void) {
	int E, S, M;

	cin >> E >> S >> M;
	int ret = solution(E, S, M);
	cout << ret;
	return 0;
}
