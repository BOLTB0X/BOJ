#include <iostream>
#include <string>

using namespace std;

string board[101];

pair<int, int> solution(int n) {
	pair<int, int> answer = { 0,0 };
	int cnt;

	// 가로
	for (int i = 0; i < n; ++i) {
		cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == '.') 
				cnt++;

			//  무조건 몸을 쭉 뻗기 때문에 반드시 벽이나 짐에 닿게 된다.
			else {
				if (cnt >= 2) 
					answer.first++;
				cnt = 0;
			}
		}
		if (cnt >= 2)
			answer.first++;
	}

	// 세로
	for (int i = 0; i < n; ++i) {
		cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (board[j][i] == '.') 
				cnt++;

			//  무조건 몸을 쭉 뻗기 때문에 반드시 벽이나 짐에 닿게 된다.
			else {
				if (cnt >= 2)
					answer.second++;
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
	for (int i = 0; i < n; ++i)
		cin >> board[i];

	pair<int, int> ret = solution(n);
	cout << ret.first << ' ' << ret.second;
	return 0;
}
