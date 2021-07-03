#include <iostream>
#include <string>
using namespace std;

int T;//테스트 변수

void solution(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s; //문자열
		bool check[26] = { false, }; //체크 배열

		cin >> s;
		int tot = 0;
		for (int j = 0; j < s.length(); j++) 
			check[(char)s[j] - 'A'] = true; //입력받은 문자열 알파벳을 체크
		for (int j = 0; j < 26; j++) { //나오지 않는 것들 합해야 하므로
			if (!check[j])
				tot += (j + 65); //A의 아스키 코드 65
		}
		cout << tot << '\n';
	}
}

int main(void) {
	solution();
	return 0;
}
