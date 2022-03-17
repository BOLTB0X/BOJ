#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int result; // 최댓값을 위한
int board[501][501];
int visited[501][501] = { 0, };

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//최대
int Max(int a, int b) {
	return a > b ? a : b;
}

//ㅜ모양 회전
void Special_Shape(int n, int m, int y, int x) {
	// ㅜ
	if (y + 1 < n && x + 2 < m)
		result = Max(result, board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x + 1]);
	
	// ㅏ
	if (y + 2 < n && x + 1 < m)
		result = Max(result, board[y][x] + board[y + 1][x] + board[y + 1][x + 1] + board[y + 2][x]);
	
	// ㅗ
	if (y - 1 >= 0 && x + 2 < m)
		result = Max(result, board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y - 1][x + 1]);
	
	// ㅓ
	if (y + 2 < n && x - 1 >= 0)
		result = Max(result, board[y][x] + board[y + 1][x] + board[y + 1][x - 1] + board[y + 2][x]);

	return;
}

// DFS
void General_Shape(int n, int m, int y, int x, int tot, int level) {
	// 1부터 시작하므로
	if (level == 3) {
		result = Max(result, tot);
		return;
	}

	// 상하좌우 차롈로
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 범위 초과
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;

		// 재방문
		if (visited[ny][nx] == 1)
			continue;

		visited[ny][nx] = 1;
		General_Shape(n, m, ny, nx, tot + board[ny][nx], level + 1);
		visited[ny][nx] = 0;
	}
	return;
}

void find_Shape(int n, int m, int y, int x) {
	//현재 위치에 탐색길이가 4인 모양 - > ㅜ인지
	Special_Shape(n, m, y, x);

	visited[y][x] = 1;
	General_Shape(n, m, y, x, board[y][x], 0);
	visited[y][x] = 0;

	return;
}

int solution(int n, int m) {
	int answer = 0;
	// 완전탐색 문제

	//초기화
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			visited[i][j] = 0;
	}

	// ㅜ제외 모양은 level 4이므로 그냥 탐색하면 됌
	// ㅜ은 ㅜ, ㅓ, ㅏ, ㅗ
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
