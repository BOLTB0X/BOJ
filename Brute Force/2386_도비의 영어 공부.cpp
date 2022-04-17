#include <iostream>
#include <string>

using namespace std;

int solution(string str, char ch) {
	int answer = 0;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32; // 소문자 변환
			if (str[i] == ch)
				answer++;
		}

		else if (str[i] >= 'a' && str[i] <= 'z') {
			if (str[i] == ch)
				answer++;
		}
	}

	return answer;
}

int main(void) {
	char ch;
	string str;

	while (1) {
		cin >> ch;

		if (ch == '#')
			break;

		getline(cin, str);
		int ret = solution(str, ch);
		cout << ch << ' ' << ret << '\n';
	}
	return 0;
}