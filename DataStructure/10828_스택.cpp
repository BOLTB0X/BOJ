#include <iostream>
#include <string>
#include <stack>

using namespace std;

void solution(void) {
	int T;
	stack<int> s;
	cin >> T;
	while (T--) {
		string cmm;
		int value;
		cin >> cmm;

		if (cmm == "push") {
			cin >> value;
			s.push(value);
		}
		else if (cmm == "pop") {
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}

		else if (cmm == "size")
			cout << s.size() << '\n';

		else if (cmm == "empty") {
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		else if (cmm == "top") {
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}