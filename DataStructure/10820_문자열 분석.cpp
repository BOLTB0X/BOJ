#include <iostream>
#include <string>

using namespace std;

int main(void) {
	//�ϴ� �ݺ�
	for (int i = 0; i < 100; ++i) {
		string str;

		//�Է�
		getline(cin, str);

		//Ż������
		if (str.length() == 0)
			break;

		int upp = 0, low = 0, blank = 0, number = 0;

		for (int j = 0; j < str.length(); ++j) {
			//�빮��
			if (str[j] >= 'A' && str[j] <= 'Z')
				upp++;
			//�ҹ���
			else if (str[j] >= 'a' && str[j] <= 'z')
				low++;
			//����
			else if (str[j] == ' ')
				blank++;
			//��
			else if (str[j] >= '0' && str[j] <= '9')
				number++;
		}

		//���
		cout << low << " " << upp << " " << number << " " << blank << '\n';
	}
	return 0;
}