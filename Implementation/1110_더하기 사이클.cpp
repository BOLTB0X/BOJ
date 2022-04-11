#include <iostream>

using namespace std;

int solution(int n) {
	int answer = 1;

	int new_tot = (n / 10) + (n % 10);
	int new_num = (n % 10) * 10 + new_tot % 10;

	while (new_num != n) {
		answer++;
		new_tot = (new_num / 10) + (new_num % 10);
		new_num = (new_num % 10) * 10 + (new_tot % 10);
	}

	return answer;
}

int main(void) {
	int n;

	cin >> n;
	int ret = solution(n);
	cout << ret;
	return 0;
}
