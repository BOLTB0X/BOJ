#include <iostream>
#define LL long long

using namespace std;

int main(void) {
	LL S;
	LL tot = 0;
	cin >> S;
	int max_number = 0, number = 1; // 결과와 더해지는 수

	while (1) {
		tot += number;
		max_number++;

		if (tot > S) {
			tot -= number;
			max_number--;
			break;
		}
		number++;
	}

	cout << max_number;

	return 0;
}
