#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string str) {
	int T;
	string answer;
	stack<char> L; // 왼쪽
	stack<char> R; // 오른쪽

	// 왼쪽에서 시작하므로
	for (char& ch : str)
		L.push(ch);
	
	cin >> T;
	while (T--) {
		char cmd;
		cin >> cmd;

		if (cmd == 'P') {
			char ch;
			cin >> ch;
			L.push(ch);
		}

		else if (cmd == 'L') {
			if (L.empty())
				continue;
			R.push(L.top());
			L.pop();
		}
		
		else if (cmd == 'D') {
			if (R.empty())
				continue;
			L.push(R.top());
			R.pop();
		}

		else if (cmd == 'B') {
			if (L.empty())
				continue;
			L.pop(); // 삭제
			// R은 그대로
		}
	}

	// -> 순으로 쌓이니
	// 출력을 위해 R에 넘겨줌
	while (!L.empty()) {
		R.push(L.top());
		L.pop();
	}

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
