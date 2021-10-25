#include <iostream>
#include <string>

using namespace std;

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;

	getline(cin, str);

	for (int i = 0; i < str.size(); ++i) {
		//공백
		if (str[i] == ' ')
			cout << ' ';

		//소문자
		else if (str[i] >= 'a' && str[i] <= 'z') {
			int tmp = (str[i] - 'a' + 13) % 26;
			cout << char(tmp + 'a');
		}

		//대문자
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			int tmp = (str[i] - 'A' + 13) % 26;
			cout << char(tmp + 'A');
		}

		else
			cout << str[i];
	}
	return 0;
}