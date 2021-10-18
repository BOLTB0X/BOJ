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
			//���� ��ȣ�� ����
			if (c == '(')
				st.push(c);

			//�ݴ� ��ȣ�� ���� �ɽ�
			//������� �ʰ� top�� ���� ��ȣ���� üũ
			else if (!st.empty() && paren[i] == ')' && st.top() == '(')
				st.pop();

			// �׿ܸ� �ȉ�
			else {
				answer = "NO";
				break;
			}
		}
		//������ üũ
		if (!st.empty())
			answer = "NO";
		cout <<answer << '\n';
	}
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