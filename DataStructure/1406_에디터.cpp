#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string str) {
	int T;
	string answer;
	stack<char> L; // 왼
	stack<char> R; // 오

	for (int i = 0; i < str.length(); ++i)
		L.push(str[i]);
	
	cin >> T;
	while (T--) {
		char ch;
		cin >> ch;

		if (ch == 'P') {
			char x;
			cin >> x;

			L.push(x);
		}

		else if (ch == 'L') {
			if (L.empty())
				continue;
			R.push(L.top());
			L.pop();
		}
		
		else if (ch == 'D') {
			if (R.empty())
				continue;
			L.push(R.top());
			R.pop();
		}

		else if (ch == 'B') {
			if (L.empty())
				continue;
			L.pop();
		}
	}

	// L을 R로 옮겨줌
	while (!L.empty()) {
		R.push(L.top());
		L.pop();
	}

	// 출력하기 위해 
	while (!R.empty()) {
		answer += R.top();
		R.pop();
	}

	return answer;
}

int main(void) {
	string str;

	cin >> str;
	string ret = solution(str);
	cout << ret;
	return 0;
}
