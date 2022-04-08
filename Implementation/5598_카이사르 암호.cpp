#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str, answer;

	cin >> str;
	/*
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == 'A')
			answer += 'X';
		else if (str[i] == 'B')
			answer += 'Y';
		else if (str[i] == 'C')
			answer += 'Z';
		else
			answer += (char)((str[i] - 3));
	}
	*/
	
	for (int i = 0; i < str.length(); ++i) {
		char tmp = str[i] - 3;

		if (tmp < 'A')
			tmp += 26; // 90ÀÌ µÇ¹Ç·Î
		answer += tmp;
	}
	
	cout << answer;
	return 0;
}
