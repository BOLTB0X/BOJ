#include <iostream>
#include <string>
#include <stack>

using namespace std;

string trans_bin(string X) {
	stack<int> bin_num;
	int size = X.length();
	for (int i = size - 1; i >= 0; i--) {
		int cur = X[i] - '0';
		//3자리씩 끊음
		for (int j = 0; j < 3; j++) {
			int r = cur % 2;
			cur /= 2;
			bin_num.push(r);
		}
	}
	//8진수 특성상 1로 시작
	while (bin_num.top() != 1) 
		bin_num.pop();
	
	string result = "";
	while (!bin_num.empty()) {
		result += to_string(bin_num.top());
		bin_num.pop();
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string X;
	cin >> X;

	if (X == "0") {
		cout << 0 << '\n';
		return 0;
	}
	
	string ret = trans_bin(X);
	cout << ret << '\n';
	return 0;
}
