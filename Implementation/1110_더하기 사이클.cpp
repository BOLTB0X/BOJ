#include <iostream>

using namespace std;

int solution(int n) {
	int answer = 1;
	int new_tot, new_num, target;

	new_num = n % 10;
	new_tot = n / 10 + n % 10;
	target = new_num * 10 + new_tot % 10;

	while (target != n) {
		answer++;
		
		new_num = target % 10;
		new_tot = target / 10 + target % 10;
		target = new_num * 10 + new_tot % 10;
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