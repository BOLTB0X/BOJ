#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solution(void) {
	int n;
	
	//�Է�
	cin >> n;
	vector<int> numbers(n + 1);
	vector<int> ngf(n + 1, -1);
	vector<int> f(1000001, 0);
	stack<int> st;

	for (int i = 1; i <= n; ++i) {
		cin >> numbers[i];
		f[numbers[i]]++;
	}

	for (int i = 1; i <= n; ++i) {
		//�����ʿ� �����鼭 ������ Ƚ���� Ŭ ���
		while (!st.empty() && f[numbers[st.top()]] < f[numbers[i]]) {
			//��ü
			ngf[st.top()] = numbers[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; ++i) {
		cout << ngf[i] << ' ';
	}
	cout << '\n';

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