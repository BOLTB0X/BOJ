#include <iostream>
#include <string>

using namespace std;

int main(void) {
	//일단 반복
	for (int i = 0; i < 100; ++i) {
		string str;

		//입력
		getline(cin, str);

		//탈출조건
		if (str.length() == 0)
			break;

		int upp = 0, low = 0, blank = 0, number = 0;

		for (int j = 0; j < str.length(); ++j) {
			//대문자
			if (str[j] >= 'A' && str[j] <= 'Z')
				upp++;
			//소문자
			else if (str[j] >= 'a' && str[j] <= 'z')
				low++;
			//공백
			else if (str[j] == ' ')
				blank++;
			//수
			else if (str[j] >= '0' && str[j] <= '9')
				number++;
		}

		//출력
		cout << low << " " << upp << " " << number << " " << blank << '\n';
	}
	return 0;
}