#include <iostream>

using namespace std;

void solution(void) {
	int E, S, M;

	//입력
	cin >> E >> S >> M;
	
	int year = 1;

	while (1) {
		if ((year - E) % 15 == 0 && 
			(year - S) % 28 == 0 && 
			(year - M) % 19 == 0) 
			break;
		year++;
	}

	cout << year << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}