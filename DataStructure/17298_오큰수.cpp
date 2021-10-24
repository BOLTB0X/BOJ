#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solution(void) {
	int n;
	cin >> n;

	//�����
	vector<int> nge(n + 1, -1);
	//����
	stack<int> st;

	//�����Ҵ�
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	for (int i = 1; i <= n; ++i) {
		//������ top�� �ʷ� ���뺸�� �� Ŀ�� ������ ������ pop
		while (!st.empty() && arr[st.top()] < arr[i]) {
			nge [st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	//���
	for (int i = 1; i <= n; ++i)
		cout << nge[i] << ' ';
	cout << '\n';

	//����
	delete[] arr;
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