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

		//������ ������ ���
		else {
			if (bar_razor[i - 1] == '(') {
				st.pop();
				//����
				answer += st.size();
			}
			else {
				st.pop();
				//�ϳ��� �߸�
				answer += 1;
			}
		}
	}

	cout << answer << '\n';
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}