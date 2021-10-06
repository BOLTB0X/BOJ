#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector<char> per;
bool visited[15] = { false, };

void last_check(string str) {
	//�������� �� ���� ���� ī��Ʈ
	int moum_cnt = 0;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (visited[i]) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
				|| str[i] == 'o' || str[i] == 'u')
				moum_cnt++;
			else
				cnt++;
		}
	}
	//���ǿ� ���� �Ǹ�
	if (moum_cnt >= 1 && cnt >= 2) {
		for (int i = 0; i < str.length(); i++) {
			//�湮�Ȱ͵鸸 ���
			if (visited[i])
				cout << str[i];
		}
		cout << '\n';
	}
	return;
}

void DFS(string s, int depth, int cur) {
	//Ż�� ����
	if (depth == L) {
		last_check(s);
		return;
	}
	// ���ձ��ϵ��� �� Ʈ��ŷ
	for (int i = cur; i < s.length(); ++i) {
		if (visited[i])
			continue;
		visited[i] = true;
		DFS(s, depth + 1, i);
		visited[i] = false;
	}
}

int main(void) {
	//�ʱ�ȭ 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//���ڿ� ���̿� ���� ���� �Է�
	cin >> L >> C;
	string str;
	for (int i = 0; i < C; ++i) {
		char c;
		cin >> c;
		str += c;
	}
	//���̿켱 �̿�
	sort(str.begin(), str.end());
	DFS(str, 0, 0);
	return 0;
}