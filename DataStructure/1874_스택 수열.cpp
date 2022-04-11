#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<char> solution(int n, vector<int>& cmd) {
	vector<char> answer;
	stack<int> st;
	int cur = 0, flag = 0;
	
	st.push(cur++);
	for (int i = 0; i < n; ++i) {
		// 원소가 크면 push
		while (st.top() < cmd[i]) {
			st.push(cur++);
			answer.push_back('+');
		}

		// 발견
		if (st.top() == cmd[i]) {
			st.pop();
			answer.push_back('-');
		}

		// 불가능한 경우
		else {
			flag = 1;
			break;
		}
	}

	// 불가능
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
