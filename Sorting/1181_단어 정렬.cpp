#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//1���� ª�� ��
//2���� ������
bool compare(string a, string b) {
	//����
	if (a.length() < b.length())
		return 1;
	else if (b.length() < a.length())
		return 0;
	else
		return a < b; //������
}

void solution(void) {
	int n;
	cin >> n;
	vector<string> str;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		str.push_back(word);
	}
	//����
	sort(str.begin(),str.end(),compare);

	//���
	for (int i = 0; i < n; i++) {
		//�ߺ� ����
		if (i>0 && str[i - 1] == str[i])
			continue;
		cout << str[i] << '\n';
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