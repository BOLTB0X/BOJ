#include <iostream>
#include <string>

using namespace std;

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;

	getline(cin, str);

	for (int i = 0; i < str.size(); ++i) {
		//����
		if (str[i] == ' ')
			cout << ' ';

		//�ҹ���
		else if (str[i] >= 'a' && str[i] <= 'z') {
			int tmp = (str[i] - 'a' + 13) % 26;
			cout << char(tmp + 'a');
		}

		//�빮��
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			int tmp = (str[i] - 'A' + 13) % 26;
			cout << char(tmp + 'A');
		}

		else
			cout << str[i];
	}
	return 0;
}