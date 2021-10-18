#include <iostream>
#include <stack>
#include <string>

using namespace std;

void solution(void) {
	int T;
	stack<char> st;

	cin >> T;

	//�Է� ���� ����
	cin.ignore();
	while (T--) {
		string words;
		//���� ���� �Է�
		getline(cin, words);

		//����� ���߱� ����
		words += " ";

		//��ȸ
		for (int i = 0; i < words.length(); ++i) {
			//������ ������ pop ��ȣ
			if (words[i] == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ' ';
			}
			//���ÿ� ����
			else 
				st.push(words[i]);
		}
		cout << '\n';
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