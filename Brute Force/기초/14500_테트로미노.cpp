#include <iostream>
#include <cstring>

using namespace std;

int result = -1;
int board[501][501];
int visited[501][501];

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// 최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

// 특별한 모양 -> ㅜ ㅓ ㅗ ㅏ
void special_shape(int n, int m, int y, int x) {
	// ㅜ
	if (x + 2 < m && y + 1 < n)
		result = Max(result, board[y][x] + board[y][x + 1] + board[y + 1][x + 1] + board[y][x + 2]);
	
	// ㅓ
	if (x - 1 >= 0 && y + 2 < n)
		result = Max(result, board[y][x] + board[y + 1][x] + board[y + 1][x - 1] + board[y + 2][x]);
	
	// ㅗ
	if (x + 2 < m && y - 1 >= 0)
		result = Max(result, board[y][x] + board[y][x + 1] + board[y - 1][x + 1] + board[y][x + 2]);
	
	// ㅏ
	if (x + 1 < m && y + 2 < n)
		result = Max(result, board[y][x] + board[y + 1][x] + board[y + 1][x + 1] + board[y + 2][x]);
	
	return;
}

// 일반 모양 dfs 로
void DFS(int n, int m, int y, int x, int tot, int level) {
	if (level == 3) {
		result = Max(result, tot);
		return;
	}

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
		DFS(n, m, ny, nx, tot + board[ny][nx], level + 1);
		visited[ny][nx] = 0;
	}
	return;
}

void find_shape(int n, int m, int y, int x) {
	// 특별한 모양
	special_shape(n, m, y, x);

	visited[y][x] = 1;
	DFS(n, m, y, x, board[y][x], 0);
	visited[y][x] = 0;
	return;
}

int solution(int n, int m) {
	int answer = 0;
	// 초기화
	for (int i = 0; i < n; ++i)
		memset(visited[i], 0, m);

	// 완전탐색 시작
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			find_shape(n, m, i, j);
	}

	answer = result;
	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
