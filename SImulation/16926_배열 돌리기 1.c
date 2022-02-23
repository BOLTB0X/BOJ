#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
	
int board[301][301];
int backup[301][301];

//출력
void print_board(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}

void solution(int n, int m, int r) {
	while (r--) {
		// (y1,x1) ------ (y2, x2)
		// (y4,x4) ------ (y3, x3)
		int y1 = 0, x1 = 0;
		int y2 = 0, x2 = m - 1;
		int y3 = n - 1, x3 = m - 1;
		int y4 = n - 1, x4 = 0;

		while (y1 < y4 && x1 < x2) {
			int tmp = board[y1][x1];

			//열 이동
			for (int i = x1; i < x2; ++i)
				board[y1][i] = board[y1][i + 1];
			//행 이동
			for (int i = y2; i < y3; ++i)
				board[i][x2] = board[i + 1][x2];
			//안
			for (int i = x3; i > x4; --i)
				board[y3][i] = board[y3][i - 1];
			for (int i = y4; i > y1; --i)
				board[i][x4] = board[i - 1][x4];
			board[y1 + 1][x4] = tmp;

			y1++, x1++;
			y2++, x2--;
			y3--, x3--;
			y4--, x4++;
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
