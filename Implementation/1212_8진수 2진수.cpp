#include <iostream>
#include <string>
#include <stack>
using namespace std;

string solution(string octal) {
	stack<int> binary;
	int len = octal.length();
	for (int i = len - 1; i >= 0; i--) {
		int cur = octal[i] - '0';
		for (int j = 0; j < 3; j++) {
			int r = cur % 2;
			cur /= 2;
			binary.push(r);
		}
	}
	//8진수 특성상 1로 시작해야함
	while (binary.top() != 1) {
		binary.pop();
	}
	string result = "";
	while (!binary.empty()) {
		result += to_string(binary.top());
		binary.pop();
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string octal;
	cin >> octal;
	if (octal == "0") {
		cout << 0 << '\n';
		return 0;
	}
	string ret = solution(octal);
	cout << ret << '\n';
	return 0;
}