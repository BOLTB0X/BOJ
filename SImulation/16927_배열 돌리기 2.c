#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int board[301][301];
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };

int MIN(int a, int b) {
	return a < b ? a : b;
}

void rotate(int n, int m, int r, int start, int size) {
	int tot_cnt = r % size;

	for (int i = 0; i < tot_cnt; ++i) {
		int tmp = board[start][start];
		int y = start, x = start, dir = 0;

		while (dir < 4) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny == start && nx == start)
				break;
			if (start <= ny && ny < n - start && start <= nx && nx < m - start) {
				board[y][x] = board[ny][nx];
				y = ny, x = nx;
			}
			else
				dir++;
		}
		board[start + 1][start] = tmp;
	}
	return;
}

void solution(int n, int m, int r) {
	int cnt = MIN(n, m) / 2;
	int row = n, col = m;

	for (int i = 0; i < cnt; ++i) {
		rotate(n, m, r, i, 2 * row + 2 * col - 4);
		row -= 2, col -= 2;
	}
	return;
}

int main(void) {
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);
	}

	solution(n, m, r);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d ", board[i][j]);
		printf("\n");
	}

	return 0;
}