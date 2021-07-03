#include <iostream>
#include <string>
using namespace std;

char s[3][8] = {};

int solution(int i) {
	int cnt = 1; //일반 카운트 변수
	int max_cnt = 1; //최대 카운트 변수
	char oj = s[i][0]; //각 행의 1열을 첫 비교대상으로 잡음 
	for (int j = 1; j < 9; j++) { //탐색 시작
		if (s[i][j] == oj) cnt += 1; //연속되면 카운트
		else { //다른 경우 
			if (cnt > max_cnt) max_cnt = cnt; //교체
				oj = s[i][j];
				cnt = 1;
		}
	}
	return max_cnt;
}

int main(void) {
	for (int i = 0; i < 3; i++) {
		cin >> s[i];
		cout << solution(i) << '\n';
	}
	return 0;
}