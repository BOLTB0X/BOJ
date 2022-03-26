#include <iostream>

using namespace std;

int solution(int E, int S, int M) {
	int year = 1;

	while (1) {
		// Year-E는 15의 배수이고, Year-S는 28의 배수이고, Year-M은 19의 배수
		// 1년 = 1, 1, 1
		// 2년 = 2, 2, 2
		// 15년 = 15, 15, 15
		// 16년 = 1, 16, 16
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