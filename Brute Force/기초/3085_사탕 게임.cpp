#include <iostream>

using namespace std;

int result;
char board[51][51];

// 행 카운트
void Count_Row(int n) {
	for (int y = 1; y <= n; ++y) {
		int cnt = 1; // 어차피 교체하므로 1로
		char cmp = board[y][1];
		for (int x = 2; x <= n; ++x) {
			if (cmp == board[y][x])
				cnt++;

			// 연속해서 먹으므로
			else {
				cnt = 1;
				cmp = board[y][x];
			}
			
			if (cnt > result)
				result = cnt;
		}
	}

	return;
}

// 열 카운트
void Count_Col(int n) {
	for (int y = 1; y <= n; ++y) {
		int cnt = 1; // 어차피 교체하므로 1로
		int cmp = board[1][y];
		for (int x = 2; x <= n; ++x) {
			if (cmp == board[x][y])
				cnt++;

			// 연속해서 먹으므로
			else {
				cnt = 1;
				cmp = board[x][y];
			}

			if (cnt > result)
				result = cnt;
		}
	}

	return;
}

int solution(int n) {
	int answer = 0;
	result = 0;

	// 먼저 다른 인접한 두 칸 탐색
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < n; ++j) {

			// 가로 스와핑
			swap(board[i][j], board[i][j + 1]);
			Count_Row(n);
			Count_Col(n);
			swap(board[i][j + 1], board[i][j]);
			
			// 세로 스와핑
			swap(board[j][i], board[j + 1][i]);
			Count_Row(n);
			Count_Col(n);
			swap(board[j + 1][i], board[j][i]);
		}
	}

	answer = result;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n);
	cout << ret;

	return 0;
}