#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int result = -1;
int board[501][501];
int visited[501][501];

const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

int MAX(int a, int b) {
	return a > b ? a : b;
}

// ㅜ모양
void find_Special_Shape(int n, int m, int y, int x) {
	//ㅜ
	if (y + 1 < n && x + 2 < m)
		result = MAX(result, board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x + 1]);
	
	//ㅓ
	if (y + 2 < n && x - 1 < m)
		result = MAX(result, board[y][x] + board[y + 1][x - 1] + board[y + 1][x] + board[y + 2][x]);
	
	//ㅗ
	if (y - 1 < n && x + 2 < m)
		result = MAX(result, board[y][x] + board[y][x + 1] + board[y - 1][x + 1] + board[y][x + 2]);
	
	//ㅏ
	if (y + 2 < n && x + 1 < m)
		result = MAX(result, board[y][x] + board[y + 1][x] + board[y + 1][x + 1] + board[y + 2][x]);

	return;
}

//DFS를 통한 백트래킹 시작
void DFS(int n, int m, int y, int x, int tot, int level) {
	if (level == 3) {
		result = MAX(result, tot);
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		//범위 초과
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;

		//재방문
		if (visited[ny][nx] == 1)
			continue;

		visited[ny][nx] = 1;
		DFS(n, m, ny, nx, tot + board[ny][nx], level + 1);
		visited[ny][nx] = 0;
	}

	return;
}

//모양 찾기
void find_Shape(int n, int m, int y, int x) {
	//현재 위치에 탐색길이가 4인 모양 - > ㅜ인지
	find_Special_Shape(n, m, y, x);

	//일반 모양 백트래킹으로 찾기
	visited[y][x] = 1;
	DFS(n, m, y, x, board[y][x], 0); //일반 모양은 길이가 3
	visited[y][x] = 0;

	return;
}

int solution(int n, int m) {
	int answer = 0;

	//탐색 시작 특정 모양을 찾아야함
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
			find_Shape(n, m, i, j);
		
	}

	answer = result;
	return answer;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);
	}

	int ret = solution(n, m);
	printf("%d", ret);

	return 0;
}
