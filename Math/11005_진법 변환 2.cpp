#include <iostream>
#include <string>
#define LL long long

using namespace std;

string solution(LL number, int type) {
	string answer = "";
	while (number > 0) {
		int mod = number % type;
		if (mod > 9)
			answer += (mod - 10 + 'A');
		else
			answer += (mod + '0');
		number /= type;
	}

	return string(answer.rbegin(), answer.rend());
}

int main(void) {
	LL number;
	int type;

	cin >> number >> type;
	string ret = solution(number, type);
	cout << ret;
	return 0;
}