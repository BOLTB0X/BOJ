#include <iostream>
#include <string>
#include <stack>

using namespace std;

void solution(void) {
	string str;
	int T;
	stack<char> L;
	stack<char> R;

	cin >> str;
	for (int i = 0; i < str.length(); ++i)
		L.push(str[i]);

	cin >> T;
	while (T--) {
		char cmm;
		cin >> cmm;
		
		//����
		if (cmm == 'P') {
			char c;
			cin >> c;
			L.push(c);
		}

		//Ŀ�� �������� �ű�
		else if (cmm == 'L') {
			if (L.empty())
				continue;
			else {
				R.push(L.top());
				L.pop();
			}
		}

		//����
		else if (cmm == 'B') {
			if (L.empty())
				continue;
			else
				L.pop();
		}

		//���������� ��ĭ �ű�
		else if (cmm == 'D') {
			if (R.empty())
				continue;
			else {
				L.push(R.top());
				R.pop();
			}
		}
	}
	//���� ���� ������ ���ÿ� �Ű���
	while (!L.empty()) {
		R.push(L.top());
		L.pop();
	}
	
	//���������̹Ƿ�
	//R�� ����� ����
	while (!R.empty()) {
		cout << R.top();
		R.pop();
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