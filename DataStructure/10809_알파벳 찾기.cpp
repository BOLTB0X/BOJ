#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct INFO {
	char ch;
	int cur;
};

//���ĺ� üũ
void check_location(vector<INFO>& v, char ch, int idx) {
	//���ĺ� ������ üũ���ش�.
	for (int i = 0; i < v.size(); ++i)
		if (v[i].ch == ch && v[i].cur == -1)
			v[i].cur = idx;

	return;
}

void solution(void) {
	string str;
	vector<INFO> alp;
	
	//���ĺ� ���� �ʱ�ȭ
	for (int i = 97; i <= 122; ++i)
		alp.push_back({ (char)i,-1 });

	cin >> str;

	//�� ���� ���ĺ� ��ġ üũ
	for (int i = 0; i < str.length(); ++i)
		check_location(alp, str[i], i);

	//���
	for (int i = 0; i < alp.size(); ++i)
		cout << alp[i].cur << ' ';
	cout << '\n';
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//�ذ�
	solution();
	return 0;
}