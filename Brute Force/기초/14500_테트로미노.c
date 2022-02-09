#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n, m, result = -1;
int board[501][501];
int visited[501][501];

const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

int MAX(int a, int b) {
	return a > b ? a : b;
}

//ㅜ모양 회전하면서 찾기
void find_Special_shape(int y, int x) {
	//ㅜ모양
	if (y + 1 < n && x + 2 < m) 
		result = MAX(result, board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x + 1]);
	//ㅏ모양
	if (y + 2 < n && x + 1 < m)
		result = MAX(result, board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y + 1][x + 1]);
	//ㅓ모양
	if (y + 2 < n && x - 1 >= 0)
		result = MAX(result, board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y + 1][x - 1]);
	//ㅗ모양
	if (y - 1 >= 0 && x + 2 < m)
		result = MAX(result, board[y][x] + board[y - 1][x + 1] + board[y][x + 1] + board[y][x + 2]);

	return;
}

void DFS(int y, int x, int tot, int level) {
	if (level == 3) {
		result = MAX(result, tot);
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;
		if (visited[ny][nx] == 0) {
			visited[ny][nx] = 1;
			DFS(ny, nx, tot + board[ny][nx], level + 1);
			visited[ny][nx] = 0;
		}
	}
	return;
}

void find_Shape(int y, int x) {
	//탐색길이가 4인 모양
	find_Special_shape(y, x);

	//일반모양
	visited[y][x] = 1;
	DFS(y, x, board[y][x], 0);
	visited[y][x] = 0;

	return;
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);
	}

	//탐색 시작
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
			find_Shape(i, j);
		
	}

	printf("%d", result);

	return 0;
}