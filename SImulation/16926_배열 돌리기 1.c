#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
	
int board[301][301];
int backup[301][301];

void print_board(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}

void solution(int n, int m, int r) {
	while (r--) {
		int y1 = 0, x1 = 0;
		int y2 = n - 1, x2 = 0;
		int y3 = n - 1, x3 = m - 1;
		int y4 = 0, x4 = m - 1;

		while ((y1 < y2) && (x1 < x4)) {
			int tmp = board[y2][x2];
			//го 
			for (int i = y2; i > y1; --i)
				board[i][x2] = board[i - 1][x2];
			//аб
			for (int j = x1; j < x4; ++j)
				board[y1][j] = board[y1][j + 1];
			//╩С
			for (int i = y4; i < y3; ++i)
				board[i][x4] = board[i + 1][x4];
			//©Л
			for (int j = x3; j > x2; --j)
				board[y3][j] = board[y3][j - 1];

			board[y2][x2 + 1] = tmp;

			y1++;
			x1++;

			y2--;
			x2++;

			y3--;
			x3--;

			y4++;
			x4--;
		}

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
	
	print_board(n, m);
	return 0;
}