#include <iostream>

using namespace std;

int result;
int board[501][501];
int visited[501][501];

// 상하좌우
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

// 최댓값
int Max(int a, int b) {
	return a > b ? a : b;
}

// ㅗ, ㅏ , ㅓ, ㅜ 
void Special_Shape(int n, int m, int y, int x) {
	// ㅗ
	if (x + 2 <= m && y - 1 >= 1)
		result = Max(result, board[y][x] + board[y][x + 1] + board[y - 1][x + 1] + board[y][x + 2]);
	
	// ㅏ
	if (x + 1 <= m && y + 2 <= n)
		result = Max(result, board[y][x] + board[y + 1][x] + board[y + 1][x + 1] + board[y + 2][x]);
	
	// ㅓ
	if (x - 1 >= 1 && y + 2 <= n)
		result = Max(result, board[y][x] + board[y + 1][x] + board[y + 1][x - 1] + board[y + 2][x]);
	
	// ㅜ
	if (x + 2 <= m && y + 1 <= n)
		result = Max(result, board[y][x] + board[y][x + 1] + board[y + 1][x + 1] + board[y][x + 2]);

	return;
}

// DFS 이용
void General_Shape(int n, int m, int y, int x, int tot, int level) {
	// 탈출 조건
	if (level == 3) {
		result = Max(tot, result);
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 범위 초과
		if (ny < 1 || nx < 1 || ny > n || nx > m)
			continue;

		if (visited[ny][nx] == 1)
			continue;

		visited[ny][nx] = 1;
		General_Shape(n, m, ny, nx, tot + board[ny][nx], level + 1);
		visited[ny][nx] = 0;
	}
	return;
}

void find_Shape(int n, int m, int y, int x) {
	// ㅗ, ㅏ , ㅓ, ㅜ  찾기

	// 현재 위치에 탐색길이가 4인 모양 - > ㅜ인지
	Special_Shape(n, m, y, x);

	visited[y][x] = 1;
	// 이제 길이 3 -> 원래는 4이지만 하날 더해주고 시작
	General_Shape(n, m, y, x, board[y][x], 0);
	visited[y][x] = 0;

	return;
}

int solution(int n, int m) {
	int answer = 0;

	result = -1; // 최댓값을 위한
	// 방문리스트 초기화
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j)
			visited[i][j] = 0;
	}
	
	// ㅜ제외 모양은 level 4이므로 그냥 탐색하면 됌
	// ㅜ은 ㅜ, ㅓ, ㅏ, ㅗ
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			// 모양 찾기
			find_Shape(n, m, i, j);
		}
	}

	answer = result;
	return answer;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n, m);
	cout << ret;

	return 0;
}
