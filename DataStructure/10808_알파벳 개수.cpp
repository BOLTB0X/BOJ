#include <iostream>
#include <vector>
#include <string>

using namespace std;

//������ ���� 
struct INFO {
	int cnt;
	char c;
};

//���ĺ� üũ
void check_cnt(vector<INFO> &v,char ch) {
	//���ĺ� ������ üũ���ش�.
	for (int i = 0; i < v.size(); ++i) 
		if (v[i].c == ch)
			v[i].cnt++;

	return;
}

void solution(void) {
	string str;
	vector<INFO> alp;

	//���ĺ����� ���� �� �ʱ�ȭ
	for (int i = 97; i <= 122; i++) 
		alp.push_back({ 0,(char)i });

	cin >> str;

	//�� ���� ���ĺ� ���� üũ
	for (int i = 0; i < str.length(); ++i) 
		check_cnt(alp, str[i]);
	
	//���
	for (int i = 0; i < alp.size(); ++i)
		cout << alp[i].cnt << ' ';
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