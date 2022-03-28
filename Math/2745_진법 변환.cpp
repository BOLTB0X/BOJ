#include <iostream>
#include <string>
#define LL long long

using namespace std;

LL solution(string number, int type) {
	LL answer = 0;
	LL size = number.length();

	for (LL i = size - 1, j = 1; i >= 0; --i, j *= type) {
		if (number[i] >= 'A')
			number[i] = '9' + number[i] - 'A' + 1;
		answer += j * (number[i] - '0');
	}
	return answer;
}

int main(void) {
	string number;
	int type;

	cin >> number >> type;
	LL ret = solution(number, type);
	cout << ret;
	return 0;
}