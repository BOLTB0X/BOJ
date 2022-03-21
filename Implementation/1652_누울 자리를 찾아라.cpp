#include <iostream>

using namespace std;

char board[101][101];

pair<int, int> solution(int n) {
	pair<int, int> answer = { 0,0 }; 

	// 먼저 가로
	for (int i = 1; i <= n; ++i) {
		int cnt = 0; // 문자열
		for (int j = 1; j <= n; ++j) {
			if (board[i][j] == '.')
				cnt++;

			else {
				if (cnt >= 2) {
					answer.first++;
					cnt = 0;
				}
				else
					cnt = 0;
			}
		}
		if (cnt >= 2) 
			answer.first++;
	}
	
	// 세로
	for (int i = 1; i <= n; ++i) {
		int cnt = 0; // 문자열
		for (int j = 1; j <= n; ++j) {
			// 빈자리이면
			if (board[j][i] == '.')
				cnt++;

			else {
				if (cnt >= 2) {
					answer.second++;
					cnt = 0;
				}
				else
					cnt = 0;
			}
		}
		if (cnt >= 2)
			answer.second++;
	}

	return answer;
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}

	pair<int,int> ret = solution(n);
	cout << ret.first << '\n' << ret.second;

	return 0;
}