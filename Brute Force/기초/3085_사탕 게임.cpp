#include <iostream>

using namespace std;

char board[51][51];
int result = 0;

// 최댓값반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int count_Row(int n) {
	int max_cnt = 1;
	for (int i = 0; i < n; ++i) {
		int cnt = 1;
		for (int j = 0; j < n - 1; ++j) {
			if (board[i][j] == board[i][j + 1])
				cnt++;
			else {
				max_cnt = Max(max_cnt, cnt);
				cnt = 1;
			}
		}
		max_cnt = Max(max_cnt, cnt);
	}
	return max_cnt;
}

int count_Col(int n) {
	int max_cnt = 1;
	for (int i = 0; i < n; ++i) {
		int cnt = 1;
		for (int j = 0; j < n - 1; ++j) {
			if (board[j][i] == board[j + 1][i])
				cnt++;
			else {
				max_cnt = Max(max_cnt, cnt);
				cnt = 1;
			}
		}
		max_cnt = Max(max_cnt, cnt);
	}
	return max_cnt;
}

int solution(int n) {
	int answer = 0;

	// 가로부터
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			// 사탕 종류가 다르다면
			if (board[i][j] != board[i][j + 1]) {
				// 교체
				swap(board[i][j], board[i][j + 1]);
				int rcnt = count_Row(n);
				int ccnt = count_Col(n);
				// 원상 복구
				swap(board[i][j + 1], board[i][j]);
				answer = Max(Max(rcnt, ccnt), answer);
			}
		}
	}
	
	// 세로
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			// 사탕 종류가 다르다면
			if (board[j][i] != board[j + 1][i]) {
				// 교체
				swap(board[j][i], board[j + 1][i]);
				int rcnt = count_Row(n);
				int ccnt = count_Col(n);
				// 원상 복구
				swap(board[j + 1][i], board[j][i]);
				answer = Max(Max(rcnt, ccnt), answer);
			}
		}
	}

	return answer;
}

int main(void) {
	int n;
	string tmp;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < n; ++j)
			board[i][j] = tmp[j];
	}

	int ret = solution(n);
	cout << ret;

	return 0;
}
