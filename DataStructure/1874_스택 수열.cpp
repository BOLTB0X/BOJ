#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solution(void) {
	int n;
	stack<int> st;
	vector<char> answer;

	cin >> n;
	//������ ��� ��
	int st_top = 0;

	while (n--) {
		int x;
		cin >> x;

		if (x > st_top) {
			while (x > st_top) {
				st.push(++st_top);
				//push�� ��ŭ +
				answer.push_back('+');
			}
			st.pop();
			answer.push_back('-');
		}

		//x�� ��ܰ����� ũ�ų� ���� ���
		else {
			bool flag = false;
			if (!st.empty()) {
				//����� x�̸�
				if (x == st.top()) 
					flag = true;
				st.pop();
				answer.push_back('-');
			}

			//���� ã�� ���Ѵٸ�
			if (!flag) {
				cout << "NO" << '\n';
				return ;
			}
		}
	}

	//answer �ϳ��� pop
	for (auto a : answer)
		cout << a << '\n';
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