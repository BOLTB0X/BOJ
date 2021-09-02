#include <iostream>
using namespace std;

int solution(long long S) {
	int number = 1;
	int max_number = 0;
	long long tot = 0;
	while (true) {
		tot += number;
		max_number++;
		if (tot > S) {
			max_number--;
			break;
		}
		number++;
	}
	return max_number;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long S;
	cin >> S;

	int ret = solution(S);
	cout << ret << '\n';
	return 0;
}