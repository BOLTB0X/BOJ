#include <iostream>

using namespace std;

int max_cnt = 0;
char board[51][51];

//행 갯수 카운트
void count_row(int n) {
	for (int y = 1; y <= n; ++y) {
		int cnt = 1;
		for (int x = 1; x <= n; ++x) {
			if (board[x][y] == board[x + 1][y])
				cnt++;
			else {
				if (cnt > max_cnt)
					max_cnt = cnt;
				cnt = 1;
			}
		}
	}
}

//행 갯수 카운트
void count_col(int n) {
	for (int y = 1; y <= n; ++y) {
		int cnt = 1;
		for (int x = 1; x <= n; ++x) {
			if (board[y][x] == board[y][x + 1])
				cnt++;
			else {
				if (cnt > max_cnt)
					max_cnt = cnt;
				cnt = 1;
			}
		}
	}
}

void solution(void) {
	int n;
	//입력
	cin >> n;
	for (int y = 1; y <= n; ++y)
		for (int x = 1; x <= n; ++x)
			cin >> board[y][x];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - 1; ++j) {
			//하나씩 교체하며 최대값 찾기
			//가로 교체
			swap(board[i][j], board[i][j + 1]);

			count_row(n);
			count_col(n);
			//원위치로 돌려놓기
			swap(board[i][j + 1], board[i][j]);

			//세로 교체
			swap(board[j][i], board[j + 1][i]);

			count_row(n);
			count_col(n);
			//원위치로 돌려놓기
			swap(board[j + 1][i], board[j][i]);
		}
	}

	cout << max_cnt << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}