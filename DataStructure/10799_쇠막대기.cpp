#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void solution(void) {
	int answer = 0;
	string bar_razor;
	stack<char> st;

	cin >> bar_razor;

	for (int i = 0; i < bar_razor.size(); ++i) {
		if (bar_razor[i] == '(')
			st.push('(');

		//절단이 시작한 경우
		else {
			if (bar_razor[i - 1] == '(') {
				st.pop();
				//길이
				answer += st.size();
			}
			else {
				st.pop();
				//하나만 잘림
				answer += 1;
			}
		}
	}

	cout << answer << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}