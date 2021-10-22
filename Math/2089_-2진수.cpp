#include <iostream>
#include <string>

using namespace std;

void solution(void) {
	int number;

	cin >> number;

	//0인 경우
	if (number == 0) {
		cout << 0 << '\n';
		return;
	}

	string str = "";
	//n이 홀수인 경우 내림을 할 수 있도록 (n-1) / -2
	while (number != 0) {
		if (number % -2 == 0) {
			str += "0";
			number /= -2;
		}
		else {
			str += "1";
			number = (number - 1) / -2;
		}
	}

	//뒤집어서 출력
	for (int i = str.length() - 1; i >= 0; --i)
		cout << str[i];
	cout << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}