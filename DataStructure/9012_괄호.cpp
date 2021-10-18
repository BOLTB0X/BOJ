#include <iostream>
#include <stack>

using namespace std;

void solution(void) {
	int T;
	
	cin >> T;
	while (T--) {
		string paren;
		stack<char> st;
		string answer = "YES";

		cin >> paren;

		for (int i = 0; i < paren.length(); ++i) {
			char c = paren[i];
			//여는 괄호면 삽입
			if (c == '(')
				st.push(c);

			//닫는 괄호가 삽입 될시
			//비어있지 않고 top이 여는 괄호인지 체크
			else if (!st.empty() && paren[i] == ')' && st.top() == '(')
				st.pop();

			// 그외면 안됌
			else {
				answer = "NO";
				break;
			}
		}
		//마지막 체크
		if (!st.empty())
			answer = "NO";
		cout <<answer << '\n';
	}
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