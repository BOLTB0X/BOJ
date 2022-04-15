#include <iostream>

using namespace std;

char board[51][51];

// 최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

// 가로
int Count_Row(int n) {
	int max_cnt = 1;

	for (int i = 0; i < n; ++i) {
		int cnt = 1;
		for (int j = 0; j < n - 1; ++j) {
			// 바로 옆이 같다면
			if (board[i][j] == board[i][j + 1])
				cnt++;

			else {
				// 갯수 비교 및 초기화
				max_cnt = Max(max_cnt, cnt);
				cnt = 1; // 초기화
			}
		}
		max_cnt = Max(max_cnt, cnt); // 갯수 비교
	}

	return max_cnt;
}

// 세로
int Count_Col(int n) {
	int max_cnt = 1;
	
	for (int i = 0; i < n; ++i) {
		int cnt = 1;
		for (int j = 0; j < n - 1; ++j) {
			// 세로 비교, 인덱스 조심
			if (board[j][i] == board[j + 1][i])
				cnt++;

			else {
				max_cnt = Max(max_cnt, cnt);
				cnt = 1; // 초기화
			}
		}
		max_cnt = Max(max_cnt, cnt);
	}

	return max_cnt;
}

int solution(int n) {
	int answer = 0;

	// 완전탐색 시작
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			// 가로에서 찾았다면
			if (board[i][j] != board[i][j + 1]) {
				swap(board[i][j], board[i][j + 1]);

				int r_cnt = Count_Row(n);
				int c_cnt = Count_Col(n);
				swap(board[i][j + 1], board[i][j]);

				answer = Max(Max(r_cnt, c_cnt), answer);
			}
		}
	}
	
	// 완전탐색 시작
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			// 세로에서 찾았다면
			if (board[j][i] != board[j + 1][i]) {
				swap(board[j][i], board[j + 1][i]);

				int r_cnt = Count_Row(n);
				int c_cnt = Count_Col(n);
				swap(board[j + 1][i], board[j][i]);

				answer = Max(Max(r_cnt, c_cnt), answer);
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
