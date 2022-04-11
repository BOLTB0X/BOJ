#include <iostream>
#include <string>
#include <vector>

using namespace std;

char stack[1001];
int top;

void push(char data) {
	stack[++top] = data;
	return;
}

vector<string> solution(string str) {
	vector<string> answer;
	string tmp = "";
	top = -1; // 초기화

	// 스택이용
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			while (top != -1) 
				tmp += stack[top--];
			answer.push_back(tmp);
			tmp = "";
		}
		else
			push(str[i]);
	}
	while (top != -1)
		tmp += stack[top--];
	answer.push_back(tmp);

	return answer;
}

int main(void) {
	int T;
	
	cin >> T;
	cin.ignore();
	while (T--) {
		string str;
		getline(cin, str);
		vector<string> ret = solution(str);
		for (int i = 0; i < ret.size(); ++i)
			cout << ret[i] << ' ';
		cout << '\n';
	}

	return 0;
}
