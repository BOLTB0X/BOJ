#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<char> solution(int n, vector<int>& cmd) {
	vector<char> answer;
	stack<int> st; // 스택
	int cur = 0, flag = 0;

	st.push(cur++); // 먼저 0을 넣어줌
	for (int i = 0; i < n; ++i) {
		// 스택의 최상단이 작다면
		while (st.top() < cmd[i]) {
			st.push(cur++);
			answer.push_back('+');
		}

		if (st.top() == cmd[i]) {
			st.pop();
			answer.push_back('-');
		}

		else { // 전체가 불가능한 경우
			flag = 1;
			break;
		}
	}

	if (flag == 1)
		answer.clear();
	return answer;
}

int main(void) {
	int n;
	vector<int> cmd;

	cin >> n;
	cmd.resize(n);
	for (int i = 0; i < n; ++i) 
		cin >> cmd[i];

	vector<char> ret = solution(n, cmd);
	if (ret.size() == 0)
		cout << "NO";
	else {
		for (char& r : ret)
			cout << r << '\n';
	}
	return 0;
}
