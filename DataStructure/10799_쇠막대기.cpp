#include <iostream>
#include <string>
#include <stack>

using namespace std;

void solution(void) {
	int answer = 0;
	string bar_razor;
	stack<char> st;

	//입력
	cin >> bar_razor;

	//쇠막대기 길이만큼 순회하면서 얼마나 잘리는지 확인
	for (int i = 0; i < bar_razor.length(); ++i) {
		//여는 괄호인 경우
		if (bar_razor[i] == '(')
			st.push(bar_razor[i]);
		//닫는 괄호 즉 잘리는 경우
		else {
			//여러개 잘리는 경우
			if (bar_razor[i-1] == '(') {
				st.pop();
				//잘린만큼 더해줌
				answer += st.size();
			}
			//하나만 잘리는 경우
			else {
				st.pop();
				answer += 1;
			}
		}
	}

	//정답 출력
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
