#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
int n;

void solution(string s) {
	stack<char> L;
	stack<char> R;
	for (int i = 0; i < s.length(); i++) 
		L.push(s[i]);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		char cmd;
		cin >> cmd;
		if (cmd == 'P') {
			char c;
			cin >> c;
			L.push(c);
		}
		else if (cmd == 'L') {
			if (L.empty()) 
				continue;
			else {
				R.push(L.top());
				L.pop();
			}
		}
		else if (cmd == 'B') {
			if (L.empty())
				continue;
			else
				L.pop();
		}
		else if (cmd == 'D') {
			if (R.empty())
				continue;
			else {
				L.push(R.top());
				R.pop();
			}
		}
	}
	while (!L.empty()) {
		R.push(L.top());
		L.pop();
	}
	while (!R.empty()) {
		cout << R.top();
		R.pop();
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	solution(str);
	return 0;
}